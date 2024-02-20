#include "../../include/mobs/Elf.hpp"

Elf::Elf(const int64_t __x, const int64_t __y) : 
    NPC(NPCType::Elf, "Elf_" + std::to_string(id++), __x, __y) 
{
}

std::string Elf::get_type() 
{
    return "Elf";
}

int64_t Elf::get_damage_range() const
{
    return 50;
}

void Elf::battle_cry() const
{
    std::cout << "*Elfic sounds*!!!" << std::endl;
}

bool Elf::accept(std::shared_ptr<NPC> visitor) 
{
    if (visitor->fight(std::shared_ptr<Elf>(this, [](Elf*) {}))) {
        return true;
    }
    return false;
}

bool Elf::fight(std::shared_ptr<Knight> accepter) 
{
    if (this->get_energy() > accepter->get_energy()) {
        notify_killed(accepter);
        accepter->must_die();
        return true;
    }
    return true;
}

bool Elf::fight(std::shared_ptr<Elf> accepter) 
{
    return false;
}

bool Elf::fight(std::shared_ptr<Dragon> accepter) 
{
    return false;
}

void Elf::move(const int64_t max_x, const int64_t max_y)
{
    std::lock_guard<std::shared_mutex> lck(_mutex);
    double angle = static_cast<double>(std::rand() % 100) / 100 * 2 * M_PI,
           dist = static_cast<double>(std::rand() % 100) / 100 * 10;

    int shift_x = static_cast<int>(dist * std::cos(angle)),
        shift_y = static_cast<int>(dist * std::sin(angle));

    if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
        _x += shift_x;
    if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
        _y += shift_y;
}
