#include"bin_tree.h"
#include"marsh.h"
#include"menu.h"
using namespace std;

int main() {
	bin_tree<marsh> all_marsh;
	build_menu(all_marsh);

	system("pause");
	return 0;
}