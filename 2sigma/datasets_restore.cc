/*
 * input: a number of datacenters and the IDs of datasets stores in each
 * datacenter.
 *
 * format:
 *   number-of-datacenters
 *   [number-of-datasets [dataset-id]*number-of-datasets]*number-of-datacenters
 * 
 * output: a list of minimal number of copies to make every datacenter has
 * every dataset. Datacenter ID begins from 1;
 *
 * format:
 *   [dataset-id from-datacenter-id to-datacenter-id]*
 *   done
 * 
 * example:
 * input:
 * 2
 * 2 1 2
 * 2 2 1
 * output:
 * done
 */

#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <iterator>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string buf;
    int l;
    cin >> l;
    getline(cin, buf); // get rid of the newline after l

    map<int, set<int> > datasets;
    for (int i = 0; i < l; ++i) {
        getline(cin, buf);
        stringstream s(buf);
        string item;
        getline(s, item, ' ');
        while (getline(s, item, ' ')) {
            int id = atoi(item.c_str());
            datasets[id].insert(i);
            /*
             * cout << "id=" << id << ",dc=" << i << endl;
             */
        }
    }
    for (map<int, set<int> >::iterator it = datasets.begin(), ie = datasets.end();
         it != ie; ++it) {
        int id = it->first;
        set<int> &dcs = it->second;

        /*
         * cout << "id=" << id << ":";
         * copy(dcs.begin(), dcs.end(), ostream_iterator<int>(cout, " "));
         * cout << endl;
         */

        int from = *dcs.begin();
        for (int i = 0; i < l; ++i) {
            if (dcs.find(i) == dcs.end()) {
                cout << id << " " << from + 1 << " " << i + 1 << endl;
            }
        }
    }
    cout << "done" << endl;
    return 0;
}
