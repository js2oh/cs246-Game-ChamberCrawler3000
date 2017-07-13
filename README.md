```
*Abstract Class*

├── Cell
├── Chamber
├── Floor
├── TextDisplay???
├── (*Subject*)
├── (*Observer*)
│
├── character/
│   ├── *Character*
│   ├── (*CharacterFactory*)
│   │
│   ├── character/enemy/
│   │   ├── Dragon
│   │   ├── Dwarf
│   │   ├── Elf
│   │   ├── *Enemy*
│   │   ├── (EnemyFactory)
│   │   ├── Halfling
│   │   ├── Human
│   │   ├── Merchant
│   │   ├── Orc
│   │
│   └── character/player/
│       ├── Drow
│       ├── Goblin
│       ├── *Player*
│       ├── (PlayerFactory)
│       ├── Shade
│       ├── Troll
│
├── item/
│   ├── *Item*
│   ├── (*ItemFactory*)
│   │
│   ├── item/potion/
│   │   ├── BoostAtk
│   │   ├── BoostDef
│   │   ├── Poison
│   │   ├── *Potion*
│   │   ├── (PotionFactory)
│   │   ├── Restore
│   │   ├── WoundAtk
│   │   ├── WoundDef
│   │
│   ├── item/treasure/
│   │   ├── *Treasure*
│   │   ├── (TreasureFactory)
```