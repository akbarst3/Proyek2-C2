#ifndef HEAD078_H
#define HEAD078_H

#include <string>
#include <vector>
#include <algorithm>

class PlayfairCipher {
private:
    std::string key;
    char matrix[5][5];

    void prepareKey();
    void prepareMatrix();
    void getCoordinates(char ch, int& row, int& col);
    std::string fixText(const std::string& text);

public:
    PlayfairCipher(const std::string& key);
    std::string encrypt(const std::string& plaintext);
};

#endif  
