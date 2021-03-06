/*
 * Copyright (C) 2015 Emeric Poupon
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

#pragma once

#include <Wt/WContainerWidget>
#include <Wt/WSignal>

#include "MobilePlayQueueEvents.hpp"

namespace UserInterface {
namespace Mobile {

class ReleaseView : public Wt::WContainerWidget
{
	public:

		static Wt::WLink getLink(Database::Release::id_type id);

		ReleaseView(PlayQueueEvents& events, Wt::WContainerWidget *parent = 0);

		void search(Database::SearchFilter filter, size_t nb);

		// Slots
		Wt::Signal<void>&		moreTracksSelected() { return _sigMoreTracksSelected;}

	private:

		Wt::Signal<void>	_sigMoreTracksSelected;

		void clear(void);
		void addResults(size_t nb);

		PlayQueueEvents& _events;
		Wt::WTemplate*	_showMore;

		Database::SearchFilter _filter;
		std::size_t	_nbTracks;

		// Main container that holds the releases
		Wt::WContainerWidget* _releaseContainer;

		// Used to add more results on the fly
		Database::Release::id_type	_currentReleaseId;
		Wt::WContainerWidget*		_currentTrackContainer;
};

} // namespace Mobile
} // namespace UserInterface

