#ifndef COMBINATORICS_H
#define COMBINATORICS_H

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

#endif // COMBINATORICS_H
