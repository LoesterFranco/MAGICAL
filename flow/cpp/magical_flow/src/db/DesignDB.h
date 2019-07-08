/**
 * @file DesignDB.h
 * @brief Database for the hierarchical design
 * @author Keren Zhu
 * @date 06/17/2019
 */

#ifndef MAGICAL_FLOW_DESIGN_DB_H_
#define MAGICAL_FLOW_DESIGN_DB_H_

#include "GraphComponents.h"
#include "CktGraph.h"
#include "PhysicalProp.h"

PROJECT_NAMESPACE_BEGIN

/// @class MAGICAL_FLOW::DesignDB
/// @brief the database class for the hierarchical flow
class DesignDB
{
    public:
        /// @brief default constructor
        explicit DesignDB() = default;
        /*------------------------------*/ 
        /* Getters                      */
        /*------------------------------*/ 
        /// @brief get the circuit hierarchical tree
        /// @return the circuit hierarchical tree
        const std::vector<CktGraph> & ckts() const { return _ckts; }
        /// @brief get the circuit hierarchical tree
        /// @return the circuit hierarchical tree
        std::vector<CktGraph> & ckts() { return _ckts; }
        /// @brief get the number of circuits
        /// @return the number of circuits
        IndexType numCkts() const { return _ckts.size(); }
        /// @brief get a sub circuit
        /// @param the index of the sub circuit
        /// @return the sub circuit in the hierarchical tree
        CktGraph & subCkt(IndexType idx) { return _ckts.at(idx); }
        /// @brief get the index of the root node
        /// @return the index of the root node
        IndexType rootCktIdx() const { return _rootCkt; }
        /// @brief get PhyPropDB
        /// @return the physical property DB
        PhyPropDB & phyPropDB() { return _phyPropDB; }
        /*------------------------------*/ 
        /* Vector operation             */
        /*------------------------------*/ 
        /// @brief allocate a new sub circuit 
        /// @return the index of the new sub circuit
        IndexType allocateCkt() { _ckts.emplace_back(CktGraph()); return _ckts.size() - 1; }
        
        /*------------------------------*/ 
        /* Maintainence of the hierarch */
        /*------------------------------*/ 
        /// @brief topological sort of the hierarchical tree. The top level therefore is surely placed at the first level
        /// @return if successful
        bool findRootCkt();
    private:
        std::vector<CktGraph> _ckts; ///< The hierarchical tree of the circuits. Each circuit is represented as a graph.
        IndexType _rootCkt = INDEX_TYPE_MAX; ///< The root node of the hierarchy. Should have only one.
        PhyPropDB _phyPropDB; ///< Store the property of each specific devices
};

PROJECT_NAMESPACE_END

#endif //MAGICAL_FLOW_DESIGN_DB_H_