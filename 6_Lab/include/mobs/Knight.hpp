#pragma once

#include "NPC.hpp"
#include "Elf.hpp"
#include "Dragon.hpp"

class Knight : public NPC {
  public:
    Knight(const int64_t, const int64_t);

    std::string get_type() override;

    void battle_cry() const override;

    bool accept(std::shared_ptr<NPC>) override;
    bool fight(Elf&) override;
    bool fight(Knight&) override;
    bool fight(Dragon&) override;
};

