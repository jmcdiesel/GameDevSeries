//
// Created by Joshua McDonald on 9/26/16.
//

#ifndef VIDEOSERIESGAME_EVENTHANDLER_H
#define VIDEOSERIESGAME_EVENTHANDLER_H

#include <SDL2/SDL.h>
#include <functional>
#include <vector>
#include <map>

typedef std::function<bool(SDL_Event *)> cbEvent;

class EventHandler {

    std::map<Uint32, std::vector<cbEvent>> _events;

public:

    EventHandler();
    ~EventHandler();

    bool handleEvents();
    void registerEvent(Uint32 evtType, cbEvent);

};


#endif //VIDEOSERIESGAME_EVENTHANDLER_H
