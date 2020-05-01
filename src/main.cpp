#include "App.h"

int main()
{
    App app;
    if (app.setup()) {
        app.run();
    }
    return 0;
}