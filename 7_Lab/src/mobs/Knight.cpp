#include "../../include/mobs/Knight.hpp"

Knight::Knight(const int64_t __x, const int64_t __y) : 
    NPC(NPCType::Knight, "Knight_" + std::to_string(id++), __x, __y) 
{
}

std::string Knight::get_type() 
{
    return "Knight";
}

int64_t Knight::get_damage_range() const
{
    return 10;
}

void Knight::battle_cry() const
{
    std::cout << "Bar-rr-a!!!" << std::endl;
}

bool Knight::accept(std::shared_ptr<NPC> visitor) 
{
    if (visitor->fight(std::shared_ptr<Knight>(this, [](Knight*) {}))) {
        return true;
    }
    return false;
}

bool Knight::fight(std::shared_ptr<Knight> accepter) 
{
    return false;
}

bool Knight::fight(std::shared_ptr<Elf> accepter) 
{
    return false;
}

bool Knight::fight(std::shared_ptr<Dragon> accepter) 
{
    if (this->get_energy() > accepter->get_energy()) {
        notify_killed(accepter);
        accepter->must_die();
        return true;
    }
    return true;
}

void Knight::move(const int64_t max_x, const int64_t max_y)
{
    std::lock_guard<std::shared_mutex> lck(_mutex);
    double angle = static_cast<double>(std::rand() % 100) / 100 * 2 * M_PI,
           dist = static_cast<double>(std::rand() % 100) / 100 * 30;

    int shift_x = static_cast<int>(dist * std::cos(angle)),
        shift_y = static_cast<int>(dist * std::sin(angle));

    if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
        _x += shift_x;
    if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
        _y += shift_y;
}
