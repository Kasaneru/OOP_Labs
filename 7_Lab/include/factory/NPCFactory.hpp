#pragma once

#include <fstream>

#include "../mobs/NPC.hpp"
#include "../mobs/Elf.hpp"
#include "../mobs/Knight.hpp"
#include "../mobs/Dragon.hpp"
#include "../observers/ConsoleObserver.hpp"
#include "../observers/LogObserver.hpp"

class NPCFactory final {
  public:
    NPCFactory() = default;
    virtual ~NPCFactory() = default;

    std::shared_ptr<NPC> create_NPC(NPCType, const int64_t, const int64_t);

    void save(const set_t&, const std::string&);
    set_t load(const std::string&);
};
