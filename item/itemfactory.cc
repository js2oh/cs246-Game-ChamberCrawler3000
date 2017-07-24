#include "itemfactory.h"
#include "potion/restore.h"

using namespace std;

// unique_ptr <Item> *createItem(ItemType it) {
Item *ItemFactory::createItem(ItemType it) {
    switch (it) {
        case RH:
            return new Restore();
            // return unique_ptr <Item> (new Restore());
    }
}