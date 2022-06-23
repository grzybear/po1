#include "Description.h"

Description::Description() {
	content = "Movement: Arrows\nSpecial Ability: Space Bar\nSave: S\nLoad: R\nExit: X\n";
}
std::ostream& operator<<(std::ostream& os, const Description& desc) {
	desc.Print(os);
	return os;
}
void Description::Print(std::ostream& out) const {
	out << content;
};
