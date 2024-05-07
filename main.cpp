//Дрягалова Светлана
//Б18

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <functional>

template <typename State>
class FiniteAutomat {
private:
    std::unordered_set<State> states;
    std::unordered_set<char> alphabet;
    std::function<State(State, char)> transition;
    State current_state;
    std::unordered_set<State> final_states;

public:
    FiniteAutomat(const std::unordered_set<State>& states, const std::unordered_set<char>& alphabet,
                  const std::function<State(State, char)>& transition, State initial_state, const std::unordered_set<State>& final_states)
        : states(states), alphabet(alphabet), transition(transition), current_state(initial_state), final_states(final_states) {}

    bool operator()(const std::string& input_chain) {
        for (char symbol : input_chain) {
            if (alphabet.find(symbol) == alphabet.end()) {
                return false; // Symbol is not in the alphabet
            }
            State next_state = transition(current_state, symbol);
            if (states.find(next_state) == states.end()) {
                return false; // Transition led to an invalid state
            }
            current_state = next_state;
        }
        return final_states.find(current_state) != final_states.end();
    }
};

template <typename State>
class KMPSubstringSearch {
private:
    std::string pattern;
    std::vector<int> prefix_function;

public:
    KMPSubstringSearch(const std::string& pattern) : pattern(pattern) {
        size_t m = pattern.length();
        prefix_function.resize(m);

        prefix_function[0] = 0;
        int k = 0;
        for (size_t q = 1; q < m; ++q) {
            while (k > 0 && pattern[k] != pattern[q]) {
                k = prefix_function[k - 1];
            }
            if (pattern[k] == pattern[q]) {
                k++;
            }
            prefix_function[q] = k;
        }
    }

    int transition(int state, char symbol) {
        int q = state;
        while (q > 0 && pattern[q] != symbol) {
            q = prefix_function[q - 1];
        }
        if (pattern[q] == symbol) {
            q++;
        }
        return q;
    }
};

int main() {
    std::string text = "ABABDABACDFABABCABAB";
    std::string pattern = "ABABCABAB";
    std::unordered_set<size_t> states = {0, 1, 2, 3, 4};
    std::unordered_set<char> alphabet(text.begin(), text.end());
    std::unordered_set<size_t> final_states = {4};
    KMPSubstringSearch<int> kmp(pattern);

    auto transition_function = [&kmp](size_t state, char symbol) {
        return kmp.transition(state, symbol);
    };

    FiniteAutomat<size_t> automat(states, alphabet, transition_function, 0, final_states);

    if (automat(text)) {
        std::cout << "Substring found in the text.\n";
    } else {
        std::cout << "Substring not found in the text.\n";
    }
    return 0;
}
