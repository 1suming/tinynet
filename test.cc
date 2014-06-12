#include "reactor.h"
#include "event_handle_srv.h"
#include <stdio.h>

class Server_Impl : public Event_Handle_Srv
{
public:
	Server_Impl(Reactor* __reactor,const char* __host = "0.0.0.0",unsigned int __port = 9876) : Event_Handle_Srv(__reactor,__host,__port) {}

	~Server_Impl() {}

	void on_connected(int __fd) { printf("on_connected __fd = %d \n",__fd);}

	void on_read(int __fd) { printf("on_read __fd = %d\n",__fd);}
};

int main()
{
	/*	
	g++ -g -D__LINUX -D__HAVE_SELECT -o test reactor.h reactor.cc event_handle.h event_handle_srv.h event_handle_srv.cc reactor_impl.h reactor_impl_select.h reactor_impl_select.cc test.cc
	g++ -g -D__LINUX -D__HAVE_EPOLL -o test reactor.h reactor.cc event_handle.h event_handle_srv.h event_handle_srv.cc reactor_impl.h reactor_impl_epoll.h reactor_impl_epoll.cc test.cc
	g++ -g -D__LINUX -D__HAVE_POLL -o test reactor.h reactor.cc event_handle.h event_handle_srv.h event_handle_srv.cc reactor_impl.h reactor_impl_poll.h reactor_impl_poll.cc test.cc
	*/
	Reactor* __reactor = Reactor::instance();
	Server_Impl __event_handle_srv(__reactor);
	__reactor->event_loop(5000*1000);
	return 0;
}
