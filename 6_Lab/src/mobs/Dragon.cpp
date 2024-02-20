#include "../../include/mobs/Dragon.hpp"

Dragon::Dragon(const int64_t __x, const int64_t __y) : 
    NPC(NPCType::Dragon, "Dragon_" + std::to_string(id++), __x, __y) 
{
}

std::string Dragon::get_type() 
{
    return "Dragon";
}

void Dragon::battle_cry() const
{
    std::cout << "ROOAARRHH!!!" << std::endl;
}

bool Dragon::accept(std::shared_ptr<NPC> visitor) 
{
    if (visitor->fight(*this)) {
        this->_alive = false;
        return true;
    }

    return false;
}

bool Dragon::fight(Knight& accepter) 
{
    notify_killed(accepter);
    return true;
}

bool Dragon::fight(Elf& accepter) 
{
    notify_killed(accepter);
    return true;
}

bool Dragon::fight(Dragon& accepter) 
{
    notify_killed(accepter);
    return true;
}
