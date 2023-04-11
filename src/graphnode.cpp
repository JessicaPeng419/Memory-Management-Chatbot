#include <iostream>
#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    std::cout << "GraphNode Destructor"<< std::endl;
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// move the ownership to graphnode 
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}


void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    // transfer node to current GraphNode member 
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}


void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // trasfer chatbot to the new node
    newNode->MoveChatbotHere(std::move(_chatBot));
}


GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{

    return _childEdges[index].get();

}