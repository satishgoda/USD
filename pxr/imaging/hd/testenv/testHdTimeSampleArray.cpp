//
// Copyright 2021 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/imaging/hd/timeSampleArray.h"
#include "pxr/base/tf/errorMark.h"

PXR_NAMESPACE_USING_DIRECTIVE

int 
main(int argc, char **argv)
{
    TfErrorMark errorMark;

    //
    // HdResampleNeighbors
    //
    {
        // Exact values at endpoints
        TF_VERIFY( HdResampleNeighbors(0.0f, VtValue(0.0f), VtValue(256.0f)).Get<float>() == 0.0f );
        TF_VERIFY( HdResampleNeighbors(1.0f, VtValue(0.0f), VtValue(256.0f)).Get<float>() == 256.0f );

        // Interpolation -- we don't check exact values, just approximate intervals here
        TF_VERIFY( HdResampleNeighbors(0.25f, VtValue(0.0f), VtValue(256.0f)).Get<float>() > 63.0f );
        TF_VERIFY( HdResampleNeighbors(0.25f, VtValue(0.0f), VtValue(256.0f)).Get<float>() < 65.0f );
        TF_VERIFY( HdResampleNeighbors(0.50f, VtValue(0.0f), VtValue(256.0f)).Get<float>() > 127.0f );
        TF_VERIFY( HdResampleNeighbors(0.50f, VtValue(0.0f), VtValue(256.0f)).Get<float>() < 129.0f );
        TF_VERIFY( HdResampleNeighbors(0.75f, VtValue(0.0f), VtValue(256.0f)).Get<float>() > 191.0f );
        TF_VERIFY( HdResampleNeighbors(0.75f, VtValue(0.0f), VtValue(256.0f)).Get<float>() < 193.0f );

        // Extrapolation
        TF_VERIFY( HdResampleNeighbors(-1.0f, VtValue(0.0f), VtValue(256.0f)).Get<float>() > -257.0f );
        TF_VERIFY( HdResampleNeighbors(-1.0f, VtValue(0.0f), VtValue(256.0f)).Get<float>() < -255.0f );
        TF_VERIFY( HdResampleNeighbors(+2.0f, VtValue(0.0f), VtValue(256.0f)).Get<float>() > 511.0f );
        TF_VERIFY( HdResampleNeighbors(+2.0f, VtValue(0.0f), VtValue(256.0f)).Get<float>() < 513.0f );

        // Coding error with mismatched types
        TF_VERIFY(errorMark.IsClean());
        HdResampleNeighbors(0.5f, VtValue(1.0), VtValue(2.0f)); // double != float
        TF_VERIFY(!errorMark.IsClean());
        errorMark.Clear();

        // Coding error with empty values
        TF_VERIFY(errorMark.IsClean());
        HdResampleNeighbors(0.5f, VtValue(1.0), VtValue());
        TF_VERIFY(!errorMark.IsClean());
        errorMark.Clear();    
    }

    //
    // HdResampleRawTimeSamples
    //
    {
        float times[] = {0.0f, 1.0f};
        float values[] = {0.0f, 256.0f};

        // Exact values at endpoints
        TF_VERIFY( HdResampleRawTimeSamples(0.0f, 2, times, values) == 0.0f );
        TF_VERIFY( HdResampleRawTimeSamples(1.0f, 2, times, values) == 256.0f );

        // Interpolation
        TF_VERIFY( HdResampleRawTimeSamples(0.25f, 2, times, values) > 63.0f );
        TF_VERIFY( HdResampleRawTimeSamples(0.25f, 2, times, values) < 65.0f );
        TF_VERIFY( HdResampleRawTimeSamples(0.50f, 2, times, values) > 127.0f );
        TF_VERIFY( HdResampleRawTimeSamples(0.50f, 2, times, values) < 129.0f );
        TF_VERIFY( HdResampleRawTimeSamples(0.75f, 2, times, values) > 191.0f );
        TF_VERIFY( HdResampleRawTimeSamples(0.75f, 2, times, values) < 193.0f );

        // Extrapolation -- this returns constant values outside the sample range.
        TF_VERIFY( HdResampleRawTimeSamples(-1.0f, 2, times, values) == 0.0f );
        TF_VERIFY( HdResampleRawTimeSamples(+2.0f, 2, times, values) == 256.0f );

        // Coding error with empty sample list
        TF_VERIFY(errorMark.IsClean());
        HdResampleRawTimeSamples(0.5f, 0, times, values);
        TF_VERIFY(!errorMark.IsClean());
        errorMark.Clear();
    }

    return 0;
}
