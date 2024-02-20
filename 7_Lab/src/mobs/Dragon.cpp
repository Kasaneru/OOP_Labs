#include "../../include/mobs/Dragon.hpp"

Dragon::Dragon(const int64_t __x, const int64_t __y) : 
    NPC(NPCType::Dragon, "Dragon_" + std::to_string(id++), __x, __y) 
{
}

std::string Dragon::get_type() 
{
    return "Dragon";
}

int64_t Dragon::get_damage_range() const
{
    return 30;
}

void Dragon::battle_cry() const
{
    std::cout << "ROOAARRHH!!!" << std::endl;
}

bool Dragon::accept(std::shared_ptr<NPC> visitor) 
{
    if (visitor->fight(std::shared_ptr<Dragon>(this, [](Dragon*) {}))) {
        return true;
    }
    return false;
}

bool Dragon::fight(std::shared_ptr<Knight> accepter) 
{
    if (this->get_energy() > accepter->get_energy()) {
        notify_killed(accepter);
        accepter->must_die();
        return true;
    }
    return true;
}

bool Dragon::fight(std::shared_ptr<Elf> accepter) 
{
    if (this->get_energy() > accepter->get_energy()) {
        notify_killed(accepter);
        accepter->must_die();
        return true;
    }
    return true;
}

bool Dragon::fight(std::shared_ptr<Dragon> accepter) 
{
    if (this->get_energy() > accepter->get_energy()) {
        notify_killed(accepter);
        accepter->must_die();
        return true;
    }
    return true;
}

void Dragon::move(const int64_t max_x, const int64_t max_y)
{
    std::lock_guard<std::shared_mutex> lck(_mutex);
    double angle = static_cast<double>(std::rand() % 100) / 100 * 2 * M_PI,
           dist = static_cast<double>(std::rand() % 100) / 100 * 50;

    int shift_x = static_cast<int>(dist * std::cos(angle)),
        shift_y = static_cast<int>(dist * std::sin(angle));

    if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
        _x += shift_x;
    if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
        _y += shift_y;
}
