#pragma once

#include <map>
#include <memory>
#include <vector>
#include "user.h"
#include "msg.h"

class MsgManager
{
public:
	friend std::ostream& operator<<(std::ostream&, const MsgManager&);

	/**
	@brief Adds a user to all available users.
	@param user User to add.
	*/
	void addUser(const User& user);

	/*! @copydoc addUser */
	void addUser(User&& user);

	/**
	@brief Adds a heap allocated message.
	@param msg Message to add.
	*/
	void addMsg(Msg* msg);

	/**
	@brief Searches all emails sent with the given email and writes to std::cout.
	@param email Source address to search.
	*/
	void emailsFrom(std::string_view) const;

	/**
	@brief Serializes all data to a file.
	@param filename File to save the serialized data.
	*/
	void saveTo(std::string_view filename) const;

	/**
	@brief Updates internal information by deserializing data from a file.
	@param filename File to load the serialized data.
	*/
	void loadFrom(std::string_view filename);

private:
	std::map<std::string, User> m_users{};
	std::vector<std::unique_ptr<Msg>> m_messages{};
};
