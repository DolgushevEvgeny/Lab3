#include "stdafx.h"
#include "Car.h"

CCar::CCar()
	:m_isTurnedOn(false)
	,m_gear(0)
	,m_speed(0)
{
}

CCar::~CCar()
{
}

bool CCar::IsTurnedOn()const
{
	return m_isTurnedOn;
}

bool CCar::TurnOnEngine()
{
	if (m_isTurnedOn)
	{
		return false;
	}
	m_isTurnedOn = true;
	return m_isTurnedOn;
}

bool CCar::TurnOffEngine()
{
	if (!m_isTurnedOn)
	{
		return false;
	}
	if (m_gear == 0 && IsStopped())
	{
		m_isTurnedOn = false;
		return true;
	}
	return false;
}

int CCar::GetGear()const
{
	return m_gear;
}

int CCar::GetSpeed()const
{
	return m_speed;
}

int CCar::GetDirection()const
{
	if (IsStopped())
	{
		return 0;
	}
	if (GetGear() >= 0 && !IsStopped())
	{
		return 1;
	}
	return -1;
}

bool CCar::SetGear(const int gear)
{
	if ((gear < -1) || (gear > 5))
	{
		return false;
	}
	if (!IsTurnedOn() && gear == 0)
	{
		m_gear = gear;
		return true;
	}
	if (!IsTurnedOn())
	{
		return false;
	}
	if (!IsSpeedInRange(gear, m_speed))
	{
		return false;
	}
	if (gear == -1)
	{
		if (IsStopped())
		{
			m_gear = -1;
			return true;
		}
		return false;
	}
	if (GetGear() == -1 && !IsStopped())
	{
		if (gear == 0)
		{
			m_gear = gear;
			return true;
		}
		return false;
	}
	else
	{
		if (GetGear() == 0 && !IsStopped())
		{
			return false;
		}
	}
	m_gear = gear;
	return true;
}

bool CCar::SetSpeed(const int speed)
{
	if (!IsSpeedInRange(m_gear, speed))
	{
		return false;
	}
	m_speed = speed;
	return true;
}

bool CCar::IsStopped() const
{
	return m_speed == 0;
}

bool CCar::IsSpeedInRange(int gear, int speed) const
{
	int lowSpeed = 0;
	int topSpeed = 0;
	switch (gear)
	{
	case -1:
		lowSpeed = 0;
		topSpeed = 20;
		break;
	case 1:
		lowSpeed = 0;
		topSpeed = 30;
		break;
	case 2:
		lowSpeed = 20;
		topSpeed = 50;
		break;
	case 3:
		lowSpeed = 30;
		topSpeed = 60;
		break;
	case 4:
		lowSpeed = 40;
		topSpeed = 90;
		break;
	case 5:
		lowSpeed = 50;
		topSpeed = 150;
		break;
	default:
		lowSpeed = 0;
		topSpeed = GetSpeed();
		break;
	}
	return ((speed >= lowSpeed) && (speed <= topSpeed));
}