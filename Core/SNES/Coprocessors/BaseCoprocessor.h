#pragma once
#include "stdafx.h"
#include "Utilities/ISerializable.h"
#include "SNES/IMemoryHandler.h"
#include "MemoryType.h"

class BaseCoprocessor : public ISerializable, public IMemoryHandler
{
public:
	BaseCoprocessor() : IMemoryHandler(MemoryType::SnesRegister) {}

	virtual void Reset() = 0;

	virtual void Run() { }	
	virtual void ProcessEndOfFrame() { }
	virtual void LoadBattery() { }
	virtual void SaveBattery() { }
};