#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <vector>

typedef float chance;

class Event 
{
private:
	chance m_Probability;

public:

	chance chance()
	{
		return m_Probability;
	}
};

class EventsGroup
{
private:
	std::vector<Event> m_Pool;


public:


};

class EventsFullGroup;

class EventStack
{
	std::vector<EventsGroup>
};

#endif // !EVENTS_HPP
