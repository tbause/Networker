#pragma once

namespace Networker
{

	class libNetwork
	{

	public:
		bool						startServer(std::string Port);
		bool						startClient(std::string IPAddress, std::string Port);
		std::vector<std::string>	resolveDNSName(std::string DNSName, std::string Port);
		// bool						blockingTimer();
		// void						print(const boost::system::error_code& /*e*/, boost::asio::deadline_timer* t, int* count);
		bool						TCPServer(std::string Port);
		bool						TCPClient(std::string IPAddress, std::string Port);


		libNetwork();
		~libNetwork();
	};

	// Test Class for BOOST.ASIO Examples
	class printer
	{
	private:
		boost::asio::io_service::strand strand_;
		boost::asio::deadline_timer timer1_;
		boost::asio::deadline_timer timer2_;
		int count_;

	public:
		printer(boost::asio::io_service& io);
		~printer();
		void print1();
		void print2();

	};

}


