#pragma once

#include "NPC.hpp"
#include "Knight.hpp"
#include "Dragon.hpp"

class Elf : public NPC {
  public:
    Elf(const int64_t, const int64_t);

    std::string get_type() override;
    int64_t get_damage_range() const override;

    void battle_cry() const override;

    bool accept(std::shared_ptr<NPC>) override;
    bool fight(std::shared_ptr<Knight>) override;
    bool fight(std::shared_ptr<Elf>) override;
    bool fight(std::shared_ptr<Dragon>) override;

    void move(const int64_t, const int64_t) override;
};
