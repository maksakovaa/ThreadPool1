#include "ReqHandler.h"

using namespace std;

mutex coutLocker;

void taskFunc(int id, int delay)
{
    this_thread::sleep_for(chrono::seconds(delay));
    unique_lock<mutex> l(coutLocker);
    cout << "task " << id << " made by thread_id " << this_thread::get_id() << endl;
}


int main()
{
    srand(0);
    RequestHandler rh;
    for (int i = 0; i < 20; i++)
        rh.pushRequest(taskFunc, i, 1 + rand() % 4);
    return 0;
}