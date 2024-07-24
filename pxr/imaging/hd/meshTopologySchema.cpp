//
// Copyright 2023 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* **                                                                      ** */
/* ** This file is generated by a script.                                  ** */
/* **                                                                      ** */
/* ** Do not edit it directly (unless it is within a CUSTOM CODE section)! ** */
/* ** Edit hdSchemaDefs.py instead to make changes.                        ** */
/* **                                                                      ** */
/* ************************************************************************** */

#include "pxr/imaging/hd/meshTopologySchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/imaging/hd/meshSchema.h"

#include "pxr/base/trace/trace.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdMeshTopologySchemaTokens,
    HD_MESH_TOPOLOGY_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--

HdIntArrayDataSourceHandle
HdMeshTopologySchema::GetFaceVertexCounts() const
{
    return _GetTypedDataSource<HdIntArrayDataSource>(
        HdMeshTopologySchemaTokens->faceVertexCounts);
}

HdIntArrayDataSourceHandle
HdMeshTopologySchema::GetFaceVertexIndices() const
{
    return _GetTypedDataSource<HdIntArrayDataSource>(
        HdMeshTopologySchemaTokens->faceVertexIndices);
}

HdIntArrayDataSourceHandle
HdMeshTopologySchema::GetHoleIndices() const
{
    return _GetTypedDataSource<HdIntArrayDataSource>(
        HdMeshTopologySchemaTokens->holeIndices);
}

HdTokenDataSourceHandle
HdMeshTopologySchema::GetOrientation() const
{
    return _GetTypedDataSource<HdTokenDataSource>(
        HdMeshTopologySchemaTokens->orientation);
}

/*static*/
HdContainerDataSourceHandle
HdMeshTopologySchema::BuildRetained(
        const HdIntArrayDataSourceHandle &faceVertexCounts,
        const HdIntArrayDataSourceHandle &faceVertexIndices,
        const HdIntArrayDataSourceHandle &holeIndices,
        const HdTokenDataSourceHandle &orientation
)
{
    TfToken _names[4];
    HdDataSourceBaseHandle _values[4];

    size_t _count = 0;

    if (faceVertexCounts) {
        _names[_count] = HdMeshTopologySchemaTokens->faceVertexCounts;
        _values[_count++] = faceVertexCounts;
    }

    if (faceVertexIndices) {
        _names[_count] = HdMeshTopologySchemaTokens->faceVertexIndices;
        _values[_count++] = faceVertexIndices;
    }

    if (holeIndices) {
        _names[_count] = HdMeshTopologySchemaTokens->holeIndices;
        _values[_count++] = holeIndices;
    }

    if (orientation) {
        _names[_count] = HdMeshTopologySchemaTokens->orientation;
        _values[_count++] = orientation;
    }
    return HdRetainedContainerDataSource::New(_count, _names, _values);
}

HdMeshTopologySchema::Builder &
HdMeshTopologySchema::Builder::SetFaceVertexCounts(
    const HdIntArrayDataSourceHandle &faceVertexCounts)
{
    _faceVertexCounts = faceVertexCounts;
    return *this;
}

HdMeshTopologySchema::Builder &
HdMeshTopologySchema::Builder::SetFaceVertexIndices(
    const HdIntArrayDataSourceHandle &faceVertexIndices)
{
    _faceVertexIndices = faceVertexIndices;
    return *this;
}

HdMeshTopologySchema::Builder &
HdMeshTopologySchema::Builder::SetHoleIndices(
    const HdIntArrayDataSourceHandle &holeIndices)
{
    _holeIndices = holeIndices;
    return *this;
}

HdMeshTopologySchema::Builder &
HdMeshTopologySchema::Builder::SetOrientation(
    const HdTokenDataSourceHandle &orientation)
{
    _orientation = orientation;
    return *this;
}

HdContainerDataSourceHandle
HdMeshTopologySchema::Builder::Build()
{
    return HdMeshTopologySchema::BuildRetained(
        _faceVertexCounts,
        _faceVertexIndices,
        _holeIndices,
        _orientation
    );
}

/*static*/
HdMeshTopologySchema
HdMeshTopologySchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer)
{
    return HdMeshTopologySchema(
        fromParentContainer
        ? HdContainerDataSource::Cast(fromParentContainer->Get(
                HdMeshTopologySchemaTokens->topology))
        : nullptr);
}

/*static*/
const TfToken &
HdMeshTopologySchema::GetSchemaToken()
{
    return HdMeshTopologySchemaTokens->topology;
}

/*static*/
const HdDataSourceLocator &
HdMeshTopologySchema::GetDefaultLocator()
{
    static const HdDataSourceLocator locator =
        HdMeshSchema::GetDefaultLocator().Append(GetSchemaToken());
    return locator;
}

/*static*/
HdTokenDataSourceHandle
HdMeshTopologySchema::BuildOrientationDataSource(
    const TfToken &orientation)
{

    if (orientation == HdMeshTopologySchemaTokens->leftHanded) {
        static const HdRetainedTypedSampledDataSource<TfToken>::Handle ds =
            HdRetainedTypedSampledDataSource<TfToken>::New(orientation);
        return ds;
    }
    if (orientation == HdMeshTopologySchemaTokens->rightHanded) {
        static const HdRetainedTypedSampledDataSource<TfToken>::Handle ds =
            HdRetainedTypedSampledDataSource<TfToken>::New(orientation);
        return ds;
    }
    // fallback for unknown token
    return HdRetainedTypedSampledDataSource<TfToken>::New(orientation);
} 

PXR_NAMESPACE_CLOSE_SCOPE