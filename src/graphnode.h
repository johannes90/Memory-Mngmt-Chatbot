#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include "chatbot.h"
#include <memory> 


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    // TODO: 
    //// STUDENT CODE
    ////
    // Part 4: In files chatlogic.h / chatlogic.cpp and graphnodes.h / graphnodes.cpp change the ownership of all instances of GraphEdge in a way such that each instance of GraphNode exclusively owns the outgoing GraphEdges and holds non-owning references to incoming GraphEdges. 
    // Use appropriate smart pointers and where required, make changes to the code such that data structures and function parameters reflect the changes. 
    // When transferring ownership from class ChatLogic, where all instances of GraphEdge are created, into instances of GraphNode, make sure to use move semantics.
    // data handles (owned)
    // original: std::vector<GraphEdge *> _childEdges;  
    // part 4: edges to subsequent nodes = outgoing Graphedges -> Graphnode should owns these exclusively -> convert to smart unique ptr
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
    
    // Part 5 original: ChatBot *_chatBot;
    ChatBot _chatBot;

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge); // part 4: change to smart pointers here

    //// STUDENT CODE
    ////

    void MoveChatbotHere(ChatBot chatbot);

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */