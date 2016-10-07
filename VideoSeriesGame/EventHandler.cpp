//
// Created by Joshua McDonald on 9/26/16.
//

#include "EventHandler.h"
#include <iostream>

bool EventHandler::handleEvents() {

    SDL_Event event;
    bool result;

    while(SDL_PollEvent(&event)) {
        if (_events.find(event.type) != _events.end()) {
            for(cbEvent evt : _events[event.type]) {
                result = evt(&event);
                if(!result) {
                    return false;
                }
            }
        }
    }

    return true;

}

EventHandler::EventHandler() {

}

EventHandler::~EventHandler() {

}

void EventHandler::registerEvent(Uint32 evtType, cbEvent evt) {
    _events[evtType].push_back(evt);
}
