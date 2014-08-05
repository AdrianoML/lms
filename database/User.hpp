#ifndef DATABASE_USER_HPP
#define DATABASE_USER_HPP


#include <Wt/Auth/Dbo/AuthInfo>

namespace Database {

class User;
typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;

class User {

	public:
		static const std::size_t MaxNameLength = 15;

		// list of commonly used bitrates
		static const std::vector<std::size_t> audioBitrates;
		static const std::vector<std::size_t> videoBitrates;

		User();

		typedef Wt::Dbo::ptr<User>	pointer;

		// accessors
		static pointer			getById(Wt::Dbo::Session& session, std::string id);
		static std::vector<pointer>	getAll(Wt::Dbo::Session& session);
		static std::string		getId(pointer user);

		// write
		void setAdmin(bool admin)	{ _isAdmin = admin; }
		void setAudioBitrate(std::size_t bitrate);
		void setVideoBitrate(std::size_t bitrate);
		void setMaxAudioBitrate(std::size_t bitrate);
		void setMaxVideoBitrate(std::size_t bitrate);

		// read
		bool isAdmin() const {return _isAdmin;}
		std::size_t	getAudioBitrate() const;
		std::size_t	getVideoBitrate() const;
		std::size_t	getMaxAudioBitrate() const;
		std::size_t	getMaxVideoBitrate() const;

		template<class Action>
			void persist(Action& a)
			{
				Wt::Dbo::field(a, _maxAudioBitrate, "max_audio_bitrate");
				Wt::Dbo::field(a, _maxVideoBitrate, "max_video_bitrate");
				Wt::Dbo::field(a, _isAdmin, "admin");
				Wt::Dbo::field(a, _audioBitrate, "audio_bitrate");
				Wt::Dbo::field(a, _videoBitrate, "video_bitrate");
			}

	private:

		static const std::size_t	maxAudioBitrate = 320000;
		static const std::size_t	maxVideoBitrate = 2048000;

		static const std::size_t	defaultAudioBitrate = 128000;
		static const std::size_t	defaultVideoBitrate = 1024000;

		// Admin defined settings
		int	 	_maxAudioBitrate;
		int		_maxVideoBitrate;
		bool		_isAdmin;

		// User defined settings
		int		_audioBitrate;
		int		_videoBitrate;

};

} // namespace Databas'

#endif