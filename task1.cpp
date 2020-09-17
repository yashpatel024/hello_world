#include <bits/stdc++.h>

using namespace std;

class LRUcache{
    public:
        int size;
        deque <int> cacheItems;
        unordered_map<int,deque<int>::iterator> cacheMap;

    LRUcache(int s){
        size = s;
    }
    
    //inserting element into cache
    //with inserting position of element into hashmap
    //if already exist then moving it to top
    void set(int item){
        if(cacheMap.find(item) == cacheMap.end()){
            if(cacheItems.size() == size){
                int leastItem = cacheItems.back();
                cacheItems.pop_back();
                cacheMap.erase(leastItem);
            }
        }else{
            cacheItems.erase(cacheMap[item]);
        }
        cacheItems.push_front(item);
        cacheMap[item] = cacheItems.begin();
    }

    void printCache(){
        cout<<"Cache = ";
        for(auto item = cacheItems.begin(); item != cacheItems.end(); ++item){
            cout<<*item<<" ";
        }
        cout<<endl;
    }

    //using hashmap to access element in O(1) with updating with most recent element
    int get(int key){
        if(cacheMap.find(key) == cacheMap.end()){
            return 0;
        }else{
            auto item = cacheMap[key];
            cacheItems.erase(item);
            cacheItems.push_front(key);
            return 1;
        }
    }
};

int main(){
    int lruSize;
    cout<<"Enter LRU cache size = ";cin>>lruSize;
    LRUcache cache(lruSize);

    cout<<"\nOperations:\n1 - Insert element\n2 - Get element\n3 - Display cache\n0 - Exit\n";
    int choice, item, found;
    while(choice){
        cout<<"Choice : ";cin>>choice;
        switch(choice){
            case 1:
                cout<<"Element = ";cin>>item;
                cache.set(item);
                break;
            
            case 2:
                cout<<"Item = ";cin>>item;
                found = cache.get(item);
                found?cout<<"Found\n":cout<<"Not found\n";
                break;

            case 3:
                cache.printCache();
                break;
            
            default:
                break;
        }
    }
}