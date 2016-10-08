//
// Created by Joshua McDonald on 9/26/16.
//

#include "EventHandler.h"
#include <iostream>

std::map<Uint32, std::vector<cbEvent>> EventHandler::_events;

bool EventHandler::handleEvents() {

    SDL_Event event;
    bool result;

    while(SDL_PollEvent(&event)) {
        if (_events.find(event.type) != EventHandler::_events.end()) {
            for(cbEvent evt : EventHandler::_events[event.type]) {
                result = evt(&event);
                if(!result) {
                    return false;
                }
            }
        }
    }

    return true;

}


void EventHandler::registerEvent(Uint32 evtType, cbEvent evt) {
    EventHandler::_events[evtType].push_back(evt);
}
