#include "../../include/mobs/Elf.hpp"

Elf::Elf(const int64_t __x, const int64_t __y) : 
    NPC(NPCType::Elf, "Elf_" + std::to_string(id++), __x, __y) 
{
}

std::string Elf::get_type() 
{
    return "Elf";
}

void Elf::battle_cry() const
{
    std::cout << "*Elfic sounds*!!!" << std::endl;
}

bool Elf::accept(std::shared_ptr<NPC> visitor) 
{
    if (visitor->fight(*this)) {
        this->_alive = false;
        return true;
    }

    return false;
}

bool Elf::fight(Knight& accepter) 
{
    notify_killed(accepter);
    return true;
}

bool Elf::fight(Elf& accepter) 
{
    return false;
}

bool Elf::fight(Dragon& accepter) 
{
    return false;
}
