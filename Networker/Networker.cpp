// Networker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace Networker;

int main(int argc, char* argv[])
{
	int i;
	// Test BOOST.ASIO
	// boost::system::error_code ec;
	libNetwork	handleNetwork;

	if (argc > 1)
	{
		std::cout << "Networker Version 1 (2016)" << std::endl << std::endl;
		// Show help text
		if ((strcmp(argv[1], "-help") == 0) && (argc == 2))
		{
			// TEST OUTPUT
			std::cout << "-client [ip-address] [port]: Run Networker as a client" << std::endl << std::endl;
			std::cout << "-server [port]: Run Networker as a server" << std::endl;
		}
		// Deal with Networker Client
		else if ((strcmp(argv[1], "-client") == 0) && (argc == 4))
		{
			handleNetwork.startClient(argv[2], argv[3]);
		}
		// Deal with Networker Server
		else if ((strcmp(argv[1], "-server") == 0) && (argc == 3))
		{
			handleNetwork.startServer(argv[2]);
		}
		// Resolve DNS name to IP address
		else if ((strcmp(argv[1], "-resolve") == 0) && (argc == 4))
		{
			std::vector<std::string> IPList;
			IPList = handleNetwork.resolveDNSName(argv[2], argv[3]);
		}
		else if ((strcmp(argv[1], "-test") == 0) && (argc == 2))
		{
			boost::asio::io_service io;
			printer p(io);
			boost::thread t(boost::bind(&boost::asio::io_service::run, &io));
			io.run();
			t.join();

			//handleNetwork.blockingTimer();
		}
		// Start a TCP server
		else if ((strcmp(argv[1], "-TCPServer") == 0) && (argc == 3))
		{
			handleNetwork.TCPServer(argv[2]);
		}
		// Start a TCP client
		else if ((strcmp(argv[1], "-TCPClient") == 0) && (argc == 4))
		{
			handleNetwork.TCPClient(argv[2], argv[3]);
		}
	}
	else
	{
		std::cout << "No command line parameter. Try '-help' for help." << std::endl;
	}

	// Key input for test only
	std::cout << std::endl << "Press any key to leave program" << std::endl;
	getchar();

    return 0;
}

