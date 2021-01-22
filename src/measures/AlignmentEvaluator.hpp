#ifndef SANA_ALIGNMENTEVALUATOR_HPP
#define SANA_ALIGNMENTEVALUATOR_HPP

#include <vector>

#include "Alignment.hpp"

namespace sana {
    struct AlignmentEvaluator {
        /**
         * Return new evaluated score if the oldTarget is switched to the newTarget.
         * @param source
         * @param oldTarget
         * @param newTarget
         * @return
         */
        virtual double evaluateAlignmentChange(unsigned int source, unsigned int oldTarget, unsigned int newTarget) = 0;
        /**
         * Returns new evaluated score if target1 and target2 are switched.
         * @param source1
         * @param source2
         * @param target1
         * @param target2
         * @return
         */
        virtual double evaluateAlignmentSwap(unsigned int source1, unsigned int source2,
                unsigned int target1, unsigned int target2) = 0;

        virtual double evaluateAlignment(const sana::Alignment& alignment, Graph* G1, Graph* G2) = 0;

        virtual bool supportsIncrementalEvaluation() = 0;
    };
}
#endif
