#pragma once

#include <catboost/libs/index_range/index_range.h>

#include "pair.h"

#include <util/generic/vector.h>
#include <util/system/yassert.h>

#include <library/binsaver/bin_saver.h>


using TGroupBounds = NCB::TIndexRange<ui32>;


struct TQueryInfo : public TGroupBounds {
    TQueryInfo()
        : TGroupBounds(0)
    {
    }

    TQueryInfo(ui32 begin, ui32 end)
        : TGroupBounds{begin, end}
        , Weight(1.0f)
    {
    }

    float Weight;
    TVector<ui32> SubgroupId; // can be empty if there's no subgroup data
    TVector<TVector<TCompetitor>> Competitors;
    SAVELOAD(Begin, End, Weight, SubgroupId, Competitors);
};
