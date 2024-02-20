#pragma once

#include "NPC.hpp"
#include "Elf.hpp"
#include "Knight.hpp"

class Dragon : public NPC {
  public:
    Dragon(const int64_t, const int64_t);

    std::string get_type() override;

    void battle_cry() const override;

    bool accept(std::shared_ptr<NPC>) override;
    bool fight(Elf&) override;
    bool fight(Dragon&) override;
    bool fight(Knight&) override;
};

