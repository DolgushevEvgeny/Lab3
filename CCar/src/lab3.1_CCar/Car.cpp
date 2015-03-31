#include "stdafx.h"
#include "Car.h"

CCar::CCar()
	:m_isTurnedOn(false)
	,m_gear(0)
	,m_direction(0)
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
	if (m_gear == 0 && m_speed == 0)
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
	return m_direction;
}

bool CCar::SetGear(const int gear)
{
	if (gear >= -1 && gear <= 5)
	{
		if (!m_isTurnedOn && gear == 0)
		{
			m_gear = gear;
			return true;
		}
		if (m_isTurnedOn)
		{
			if (gear == -1)
			{
				if (m_speed == 0)
				{
					m_gear = gear;
					return true;
				}
				else
				{
					return false;
				}
			}
			SetLowGearSpeed(gear);
			SetHighGearSpeed(gear);
			int direction = GetDirection();
			if (m_speed >= m_lowGearSpeed && m_speed <= m_hignGearSpeed && m_direction == direction)
			{
				if (GetGear() == -1 && m_speed != 0)
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
					if (GetGear() == 0 && m_speed != 0)
					{
						return false;
					}
				}
				m_gear = gear;
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

void CCar::SetLowGearSpeed(const int gear)
{
	switch (gear)
	{
		case 2:
			m_lowGearSpeed = 20;
			break;
		case 3:
			m_lowGearSpeed = 30;
			break;
		case 4:
			m_lowGearSpeed = 40;
			break;
		case 5:
			m_lowGearSpeed = 50;
			break;
		default:
			m_lowGearSpeed = 0;
			break;
	}
}

void CCar::SetHighGearSpeed(const int gear)
{
	switch (gear)
	{
	case -1:
		m_hignGearSpeed = 20;
		break;
	case 1:
		m_hignGearSpeed = 30;
		break;
	case 2:
		m_hignGearSpeed = 50;
		break;
	case 3:
		m_hignGearSpeed = 60;
		break;
	case 4:
		m_hignGearSpeed = 90;
		break;
	case 5:
		m_hignGearSpeed = 150;
		break;
	default:
		m_hignGearSpeed = GetSpeed();
		break;
	}
}

bool CCar::SetSpeed(const int speed)
{
	SetLowGearSpeed(m_gear);
	SetHighGearSpeed(m_gear);
	if (speed >= m_lowGearSpeed && speed <= m_hignGearSpeed)
	{
		m_speed = speed;
		return true;
	}
	return false;
}

void CCar::SetDirection()
{
	if (GetGear() >= 0 && GetSpeed() > 0)
	{
		m_direction = 1;
	}
	else
	{
		if (GetSpeed() == 0)
		{
			m_direction = 0;
		}
		else
		{
			m_direction = -1;
		}
	}
}