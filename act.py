#!/usr/bin/python3.2

class Actor:
    mailbox = None
    facet = None

class Mailbox:
    pass

class Facet:
    actors = { }
    events = { }

    def __init__(self, actors, events):
        self.actors = actors
        self.events = events

class FacetInst:
    pass

class ActorSlot:
    name = None
    facet = None

class Event:
    msgFacet = None
    msgActor = None
    senderFacet = None
    senderActor = None
    instrs = []

    def __init__(self, msgFacet, msgActor, senderFacet, senderActor, instrs):
        self.msgFacet = msgFacet
        self.msgActor = msgActor
        self.senderFacet = senderFacet
        self.senderActor = senderActor
        self.instrs = instrs

keywords = [
    'facet',
    'actor',
    'extends',
    'on',
    'new',
    'send',
    'become'
    ]

class Command:
    pass

class FacetCmd:
    pass

facetVar = Facet(
    actors = { 'State' },
    events = {
        Event(
            )
        }
    )
