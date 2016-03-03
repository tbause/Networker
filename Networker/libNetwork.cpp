#include "stdafx.h"
#include "libNetwork.h"

// ------------------------------------------------------------------------------------------------------------
// libNetwork Class Constructor
// ------------------------------------------------------------------------------------------------------------
Networker::libNetwork::libNetwork()
{
}

// ------------------------------------------------------------------------------------------------------------
// libNetwork Class Destructor
// ------------------------------------------------------------------------------------------------------------
Networker::libNetwork::~libNetwork()
{
}

bool Networker::libNetwork::startServer(std::string Port)
{
	std::cout << "Started Server" << std::endl;
	// TEST OUTPUT
	std::cout << "MODE: Server" << std::endl;
	std::cout << "Port: " << Port << std::endl;


	return true;
}

// ------------------------------------------------------------------------------------------------------------
// libNetwork Class Function: startClient
// ------------------------------------------------------------------------------------------------------------
bool Networker::libNetwork::startClient(std::string IPAddress, std::string Port)
{
	std::cout << "Started Client. Trying to connect to " << IPAddress << ":" << Port << std::endl;

	return true;
}

// ------------------------------------------------------------------------------------------------------------
// libNetwork Class Function: resolveDNSName
// ------------------------------------------------------------------------------------------------------------
std::vector <std::string> Networker::libNetwork::resolveDNSName(std::string DNSName, std::string Port)
{
	std::vector <std::string> results;
	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;
	std::chrono::duration<double> time_span;

	std::cout << "Resolve DNS Name " << DNSName << " at Port " << Port << std::endl;

	boost::asio::io_service ios;

	boost::asio::ip::tcp::resolver::query resolver_query(DNSName, Port, boost::asio::ip::tcp::resolver::query::numeric_service);

	boost::asio::ip::tcp::resolver resolver(ios);

	boost::system::error_code ec;

	t1 = std::chrono::high_resolution_clock::now();
	boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(resolver_query, ec);
	t2 = std::chrono::high_resolution_clock::now();

	time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

	std::cout << std::endl << "[resolveDNSName] Resolution took " << time_span.count() << " seconds" << std::endl;

	if (ec != 0)
	{
		std::cout << "Failed to resolve a DNS name." << "Error Code = " << ec.value() << ". Message = " << ec.message() << std::endl;
	}
	else
	{
		boost::asio::ip::tcp::resolver::iterator it_end;

		for (; it != it_end; ++it)
		{
			boost::asio::ip::tcp::endpoint ep = it->endpoint();
			results.push_back(ep.address().to_string());
			std::cout << "DNS Name: " << DNSName << " resolves to " << ep.address() << ":" << ep.port() << std::endl;
		}
		std::cout << std::endl << results.size() << " results found" << std::endl << std::endl;
	}

	return results;
}

// ------------------------------------------------------------------------------------------------------------
// libNetwork Class Function: TCPServer
// Port      = Port to listen at
// ------------------------------------------------------------------------------------------------------------
bool Networker::libNetwork::TCPServer(std::string Port)
{
	return true;
}

// ------------------------------------------------------------------------------------------------------------
// libNetwork Class Function: TCPClient
// IPAddress = Host IP address
// Port      = Host port
// ------------------------------------------------------------------------------------------------------------
bool Networker::libNetwork::TCPClient(std::string IPAddress, std::string Port)
{
	return true;
}

// ------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------
// BOOST EXAMPLE SECTION !!!!!!!!!!!!!!!!!!!!!!!!!!!!
// ------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------

// BOOST.ASIO Tutorial Example
void Networker::printer::print1()
{
	if (count_ < 10)
	{
		std::cout << "Timer 1: " << count_ << std::endl;
		++count_;

		timer1_.expires_at(timer1_.expires_at() + boost::posix_time::seconds(1));
		timer1_.async_wait(strand_.wrap(boost::bind(&printer::print1, this)));
	}
}

void Networker::printer::print2()
{
	if (count_ < 10)
	{
		std::cout << "Timer 2: " << count_ << std::endl;
		++count_;

		timer2_.expires_at(timer2_.expires_at() + boost::posix_time::seconds(1));
		timer2_.async_wait(strand_.wrap(boost::bind(&printer::print2, this)));
	}
}

Networker::printer::printer(boost::asio::io_service& io)
	: strand_(io),
	timer1_(io, boost::posix_time::seconds(1)),
	timer2_(io, boost::posix_time::seconds(1)),
	count_(0)
{
	timer1_.async_wait(strand_.wrap(boost::bind(&printer::print1, this)));
	timer2_.async_wait(strand_.wrap(boost::bind(&printer::print2, this)));
}

Networker::printer::~printer()
{
	std::cout << "Final count is " << count_ << std::endl;
}

/* BOOST.ASIO Tutorial Example

void Networker::libNetwork::print(const boost::system::error_code& err, boost::asio::deadline_timer* t, int* count)
{
	if (*count < 5)
	{
		std::cout << *count << std::endl;
		++(*count);
		t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
		t->async_wait(boost::bind(&Networker::libNetwork::print, this, boost::asio::placeholders::error, t, count));
	}
	std::cout << "Timer finished" << std::endl;
}

bool Networker::libNetwork::blockingTimer()
{
	boost::asio::io_service io;

	int count = 0;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));

	// t.async_wait(&print);
	t.async_wait(boost::bind(&Networker::libNetwork::print, this, boost::asio::placeholders::error, &t, &count));
	io.run();

	std::cout << "Final Count = " << count << std::endl;

	return true;
}

*/