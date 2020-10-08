#ifndef KLEE_PROB_STATE_H
#define KLEE_PROB_STATE_H

#include "klee/Expr/Expr.h"

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

/**
 * This is a custom execution State to store some information during
 * execution. It store information for probabilistic execution.  
 */
namespace klee {

    class ProbExecState;
    class ETreeNode;
    
    using ETreeNodePtr = std::shared_ptr<ETreeNode>;

    /**
     * Store some custom State data in the 
     * tree ndoes for ETree. Stores probabilistic data. 
    */
    class ProbExecState {
        public:

        // Did ETree fork on this state? Yes : No
        bool forkflag = false;

        // Filling dummy data as of now for sanity checks.
        // TODO : Replace with proper structure. 
        std::string data = ""; 
        
        // TODO : Symbol table, somewhat
        std::unordered_map<std::string, std::string> symbolMapping;

        // TODO : Store the probability distribution. 
        std::vector<float> probability_dist = std::vector<float>();

        // State ID for unique uuid. 
        uint32_t stateId = 0;

        // Line number for assembly code. Store the first LOC number. 
        uint32_t assemblyLine = 0;

        // Line number of actual code for assembly code. 
        uint32_t codeLine = 0;

        // ETree node with this state, probably before a fork. 
        ETreeNode* treeNode = nullptr;
        
        ProbExecState() {}

        ProbExecState(const ProbExecState &) {}
        ProbExecState(ProbExecState &&) {}
        ~ProbExecState() = default;
       
        ProbExecState(std::string data, uint32_t stateId);
        ProbExecState(std::string data, uint32_t stateId, ETreeNode* treeNode);

        ProbExecState(bool forkflag, std::string data, uint32_t stateId, uint32_t assemblyLine, uint32_t codeLine, ETreeNode* treeNode);
    };

} // namespace klee
#endif /* KLEE_PROB_STATE_H */