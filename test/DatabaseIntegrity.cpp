/*
 * Copyright (C) 2013 Emeric Poupon
 *
 * This file is part of LMS.
 *
 * LMS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LMS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LMS.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include <Wt/Dbo/SqlConnectionPool>

#include "database/DatabaseHandler.hpp"

int main(void)
{

	try {
		std::cout << "Starting test!" << std::endl;

		// Set up the long living database session
		std::unique_ptr<Wt::Dbo::SqlConnectionPool> connectionPool(Database::Handler::createConnectionPool( "test.db"));

		Database::Handler database(*connectionPool);

		Wt::Dbo::Transaction transaction(database.getSession());

		Wt::Dbo::collection< Database::Track::pointer > tracks (Database::Track::getAll( database.getSession() ));

		std::cout << "Found " << tracks.size() << " tracks!" << std::endl;

		for (auto track : tracks)
		{
			assert( !track->getName().empty() );
			assert( !track->getGenres().empty() );
			assert( !track->getDuration().is_not_a_date_time()  );
		}

	}
	catch(std::exception& e)
	{
		std::cerr << "Caught exception " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
