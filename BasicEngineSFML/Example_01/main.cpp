#include "main.h"
#include "StateTest.h"

int main() {
	Engine engine(500, 500, "Title", false, new StateTest());
	engine.run();
}