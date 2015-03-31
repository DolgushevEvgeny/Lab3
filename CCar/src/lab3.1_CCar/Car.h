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
	void SetLowGearSpeed(const int gear);
	void SetHighGearSpeed(const int gear);
	void SetDirection();
private:
	bool m_isTurnedOn;
	int m_direction;
	int m_speed;
	int m_gear;
	int m_lowGearSpeed;
	int m_hignGearSpeed;
};