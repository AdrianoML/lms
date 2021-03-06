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

#include <vector>

#include "database/Types.hpp"

#include "image/Image.hpp"

namespace CoverArt {

class Grabber
{
	public:
		Grabber(const Grabber&) = delete;
		Grabber& operator=(const Grabber&) = delete;

		static Grabber& instance();

		std::vector<boost::filesystem::path>	getCoverPaths(const boost::filesystem::path& directoryPath, std::size_t nbMaxCovers = 1) const;
		std::vector<Image::Image>	getFromDirectory(const boost::filesystem::path& path, std::size_t nbMaxCovers = 1) const;
		std::vector<Image::Image>	getFromTrack(const boost::filesystem::path& path, std::size_t nbMaxCovers = 1) const;
		std::vector<Image::Image>	getFromTrack(Wt::Dbo::Session& session, Database::Track::id_type trackId, std::size_t nbMaxCovers = 1) const;
		std::vector<Image::Image>	getFromRelease(Wt::Dbo::Session& session, Database::Release::id_type releaseId, std::size_t nbMaxCovers = 1) const;

	private:
		Grabber();

		std::vector<boost::filesystem::path> _fileExtensions
			= {".jpg", ".jpeg", ".png", ".bmp"}; // TODO parametrize
		std::size_t _maxFileSize = 5000000;
		std::vector<boost::filesystem::path> _preferredFileNames
			= {"cover", "front"}; // TODO parametrize
};

} // namespace CoverArt

