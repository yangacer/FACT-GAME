#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
#include <list>
#include <boost/cstdint.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/system/error_code.hpp>
#include <boost/ref.hpp>
#include "SDL/SDL.h"

namespace asdl {
class sdl
{
public:
  typedef boost::function<void(boost::system::error_code, sdl&, SDL_Event)> handler_type;

  sdl() : surface_(0), queue_(256)
  {
    if( 0 > SDL_Init(SDL_INIT_EVERYTHING) )
      throw std::runtime_error("Init SDL failed");

    int flag = SDL_SWSURFACE | SDL_DOUBLEBUF;
    if(0 == (surface_ = SDL_SetVideoMode(1024,768, 32, flag)))
      throw std::runtime_error("Init SDL surface failed");
  }

  ~sdl()
  { 
    SDL_Quit();  
    std::cerr << "Quit SDL\n";
  }

  void run()
  {
    SDL_Event event;
    while(SDL_WaitEvent(&event) >=0) {
      if(event.type == SDL_QUIT) {
        boost::system::error_code ec(
          boost::system::errc::operation_canceled,
          boost::system::system_category());

        for(auto i = queue_.begin(); i != queue_.end(); ++i)
          for(auto j = i->begin(); j != i->end(); ++j)
            (*j)(ec, boost::ref(*this), SDL_Event()); 
        break;
      } else if(queue_[event.type].size()) {
        handler_type h = queue_[event.type].front();
        queue_[event.type].pop_front();
        h(boost::system::error_code(), boost::ref(*this), event);
      }
    }
  }

  void async_wait_event(boost::uint8_t type, handler_type handler)
  {
    queue_[type].push_back(handler);
  }
private:
  SDL_Surface *surface_;
  std::vector<std::list<handler_type> > queue_;
};

} // namespace asdl

void keydown_handler(boost::system::error_code ec, asdl::sdl &sdl, SDL_Event event)
{
  if(!ec) {
    std::cerr << "Keydown: " << SDL_GetKeyName(event.key.keysym.sym) << "\n";
    sdl.async_wait_event(SDL_KEYDOWN, boost::bind(&keydown_handler, _1, _2, _3));
  }
}

int main(int argc, char* argv[]) 
{ 
  using namespace std;

  try {
    asdl::sdl sdl;
    sdl.async_wait_event(SDL_KEYDOWN, boost::bind(&keydown_handler, _1, _2, _3));
    sdl.run();
  } catch ( std::exception &) {
    std::cerr << "Exception throw\n";
  }

  return 0;
}
