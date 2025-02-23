//
// Created by Ruohao L. on 22/02/2025.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    static vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> result;
        unsigned short word_index = 0; //words的index

        while (word_index < words.size())
        // Step 1: 计算当前行能容纳的单词
        {
            unsigned short total_chars = words[word_index].size(); //初始当前所有单词的长度
            unsigned short last_word_index = word_index + 1; //初始下一个单词的index

            while (last_word_index < words.size() && total_chars + words[last_word_index].size() + (last_word_index -
                word_index) <= maxWidth)
            // 注意这里当条件不再满足的时候，total_chars是对的，但last_word_index已经指向了下一个存不进去了的单词
            {
                total_chars += words[last_word_index].size(); //模拟拼接（目前还没有实际把单词放进结果字符串，只是拼长度）
                ++last_word_index;
            }

            // Step 2: 上面的while结束代表一行放满了，开始处理这一行的空格
            unsigned short num_words = last_word_index - word_index;
            unsigned short num_spaces = maxWidth - total_chars;
            string line;

            if (last_word_index == words.size() || num_words == 1)
            // Case 1: 最后一行 or 只有一个单词 -> 左对齐
            {
                for (unsigned short i = word_index; i < last_word_index; ++i)
                {
                    if (i > word_index) line += " "; // 准备加下一个单词的时候加前面一个单词后面的空格，否则第一个单词后面会没有空格
                    line += words[i];
                }
                // 末尾补空格
                line += string(maxWidth - line.size(), ' ');
            }
            else
            // Case 2: 普通行 -> 两侧对齐
            {
                unsigned short space_between = num_spaces / (num_words - 1);
                unsigned short extra_spaces = num_spaces % (num_words - 1);

                for (unsigned short i = word_index; i < last_word_index; ++i)
                {
                    if (i > word_index)
                    // 准备加下一个单词的时候加前面一个单词后面的空格，否则第一个单词后面会没有空格
                    {
                        line += string(space_between, ' '); // 平均空格
                        if (extra_spaces > 0)
                        // 额外空格从左到右加
                        {
                            line += " ";
                            --extra_spaces;
                        }
                    }
                    line += words[i];
                }
            }

            result.push_back(line);
            word_index = last_word_index; // 移动到下一行
        }

        return result;
    }
};

int main()
{
    vector<string> words = {
        "Fourscore", "and", "seven", "years", "ago", "our", "fathers", "brought", "forth", "on", "this", "continent",
        "a", "new", "nation,", "conceived", "in", "liberty", "and", "dedicated", "to", "the", "proposition", "that",
        "all", "men", "are", "created", "equal.", "Now", "we", "are", "engaged", "in", "a", "great", "civil", "war,",
        "testing", "whether", "that", "nation", "or", "any", "nation", "so", "conceived", "and", "so", "dedicated",
        "can", "long", "endure.", "We", "are", "met", "on", "a", "great", "battlefield", "of", "that", "war.", "We",
        "have", "come", "to", "dedicate", "a", "portion", "of", "that", "field", "as", "a", "final", "resting-place",
        "for", "those", "who", "here", "gave", "their", "lives", "that", "that", "nation", "might", "live.", "It", "is",
        "altogether", "fitting", "and", "proper", "that", "we", "should", "do", "this.", "But", "in", "a", "larger",
        "sense,", "we", "cannot", "dedicate,", "we", "cannot", "consecrate,", "we", "cannot", "hallow", "this",
        "ground.", "The", "brave", "men,", "living", "and", "dead", "who", "struggled", "here", "have", "consecrated",
        "it", "far", "above", "our", "poor", "power", "to", "add", "or", "detract.", "The", "world", "will", "little",
        "note", "nor", "long", "remember", "what", "we", "say", "here,", "but", "it", "can", "never", "forget", "what",
        "they", "did", "here.", "It", "is", "for", "us", "the", "living", "rather", "to", "be", "dedicated", "here",
        "to", "the", "unfinished", "work", "which", "they", "who", "fought", "here", "have", "thus", "far", "so",
        "nobly", "advanced.", "It", "is", "rather", "for", "us", "to", "be", "here", "dedicated", "to", "the", "great",
        "task", "remaining", "before", "us--that", "from", "these", "honored", "dead", "we", "take", "increased",
        "devotion", "to", "that", "cause", "for", "which", "they", "gave", "the", "last", "full", "measure", "of",
        "devotion--that", "we", "here", "highly", "resolve", "that", "these", "dead", "shall", "not", "have", "died",
        "in", "vain,", "that", "this", "nation", "under", "God", "shall", "have", "a", "new", "birth", "of", "freedom,",
        "and", "that", "government", "of", "the", "people,", "by", "the", "people,", "for", "the", "people", "shall",
        "not", "perish", "from", "the", "earth."
    };
    unsigned char maxWidth = 80;

    vector<string> result = Solution::fullJustify(words, maxWidth);
    for (const string& line: result)
    {
        cout << '"' << line << '"' << endl;
    }

    return 0;
}
