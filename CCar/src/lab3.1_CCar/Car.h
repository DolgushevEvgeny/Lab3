#pragma once

class CCar
{
public:
	CCar();
	~CCar();
	bool IsTurnedOn() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(const int gear);
	bool SetSpeed(const int speed);
	int GetGear() const;
	int GetDirection() const;
	int GetSpeed() const;
	bool IsStopped() const;
	bool IsSpeedInRange(int gear, int speed) const;
private:
	bool m_isTurnedOn;
	int m_speed;
	int m_gear;
};