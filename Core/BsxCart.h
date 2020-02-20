#pragma once
#include "stdafx.h"
#include "BaseCoprocessor.h"

class Console;
class MemoryManager;
class BsxMemoryPack;

class BsxCart : public BaseCoprocessor
{
private:
	Console* _console;
	MemoryManager* _memoryManager;
	BsxMemoryPack* _memPack;

	uint8_t* _psRam = nullptr;
	uint32_t _psRamSize = 0;
	vector<unique_ptr<IMemoryHandler>> _psRamHandlers;

	IMemoryHandler* _bBusHandler = nullptr;

	uint8_t _regs[0x10] = {};
	uint8_t _dirtyRegs[0x10] = {};
	bool _dirty = false;
	
	void UpdateMemoryMappings();

public:
	BsxCart(Console* console, BsxMemoryPack* memPack);
	virtual ~BsxCart();

	uint8_t Read(uint32_t addr) override;
	void Write(uint32_t addr, uint8_t value) override;

	void Reset() override;
	void Serialize(Serializer& s) override;

	uint8_t Peek(uint32_t addr) override;
	void PeekBlock(uint32_t addr, uint8_t* output) override;
	AddressInfo GetAbsoluteAddress(uint32_t address) override;

	uint8_t* DebugGetPsRam();
	uint32_t DebugGetPsRamSize();
};