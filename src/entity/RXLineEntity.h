/**
 * Copyright (c) 2011-2013 by Andrew Mustun. All rights reserved.
 * 
 * This file is part of the QCAD project.
 *
 * QCAD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QCAD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QCAD.
 */

#ifndef RXLINEENTITY_H
#define RXLINEENTITY_H

#include "entity_global.h"

#include "REntity.h"
#include "RXLineData.h"

class RDocument;
class RExporter;

/**
 * Infinite line entity.
 *
 * \scriptable
 * \sharedPointerSupport
 * \ingroup entity
 */
class QCADENTITY_EXPORT RXLineEntity: public REntity {

public:
    static RPropertyTypeId PropertyCustom;
    static RPropertyTypeId PropertyHandle;
    static RPropertyTypeId PropertyType;
    static RPropertyTypeId PropertyBlock;
    static RPropertyTypeId PropertyLayer;
    static RPropertyTypeId PropertyLinetype;
    static RPropertyTypeId PropertyLineweight;
    static RPropertyTypeId PropertyColor;
    static RPropertyTypeId PropertyDrawOrder;

    static RPropertyTypeId PropertyBasePointX;
    static RPropertyTypeId PropertyBasePointY;
    static RPropertyTypeId PropertyBasePointZ;
    static RPropertyTypeId PropertySecondPointX;
    static RPropertyTypeId PropertySecondPointY;
    static RPropertyTypeId PropertySecondPointZ;

    static RPropertyTypeId PropertyDirectionX;
    static RPropertyTypeId PropertyDirectionY;
    static RPropertyTypeId PropertyDirectionZ;

    static RPropertyTypeId PropertyAngle;

public:
    RXLineEntity(RDocument* document, const RXLineData& data,
        RObject::Id objectId = RObject::INVALID_ID);
    virtual ~RXLineEntity();

    static void init();

    static QSet<RPropertyTypeId> getStaticPropertyTypeIds() {
        return RPropertyTypeId::getPropertyTypeIds(typeid(RXLineEntity));
    }

    virtual RXLineEntity* clone() const {
        return new RXLineEntity(*this);
    }

    virtual RS::EntityType getType() const {
        return RS::EntityLine;
    }

    bool setProperty(RPropertyTypeId propertyTypeId, const QVariant& value,
        RTransaction* transaction=NULL);
    QPair<QVariant, RPropertyAttributes> getProperty(
            RPropertyTypeId& propertyTypeId,
            bool humanReadable = false, bool noAttributes = false);

    virtual void exportEntity(RExporter& e, bool preview=false) const;

    virtual RXLineData& getData() {
        return data;
    }

    virtual const RXLineData& getData() const {
        return data;
    }

    void setShape(const RLine& l);

    void setBasePoint(const RVector& p) {
        data.setBasePoint(p);
    }

    RVector getBasePoint() const {
        return data.getBasePoint();
    }

    void setSecondPoint(const RVector& p) {
        data.setSecondPoint(p);
    }

    RVector getSecondPoint() const {
        return data.getSecondPoint();
    }

    void setDirectionVectorPoint(const RVector& v) {
        data.setDirectionVector(v);
    }

    RVector getDirectionVector() const {
        return data.getDirectionVector();
    }

    double getAngle() const {
        return data.getAngle();
    }

    double getDirection1() const {
        return data.getDirection1();
    }

    double getDirection2() const {
        return data.getDirection2();
    }

    bool reverse() {
        return data.reverse();
    }

    RS::Side getSideOfPoint(const RVector& point) const {
        return data.getSideOfPoint(point);
    }

    RS::Ending getTrimEnd(const RVector& coord,
                            const RVector& trimPoint) {
        return data.getTrimEnd(coord, trimPoint);
    }

    void trimStartPoint(const RVector& p) {
        return data.trimStartPoint(p);
    }
    void trimEndPoint(const RVector& p) {
        return data.trimEndPoint(p);
    }

    double getLength() const {
        return data.getLength();
    }

protected:
    virtual void print(QDebug dbg) const;

protected:
    RXLineData data;
};

Q_DECLARE_METATYPE(RXLineEntity*)
Q_DECLARE_METATYPE(QSharedPointer<RXLineEntity>)
Q_DECLARE_METATYPE(QSharedPointer<RXLineEntity>*)

#endif