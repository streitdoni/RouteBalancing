//
// Generated file, do not edit! Created by nedtool 5.4 from src/routing/aodvStandard/AODVStandardControlPackets.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "AODVStandardControlPackets_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

StandardUnreachableNode::StandardUnreachableNode()
{
    this->seqNum = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const StandardUnreachableNode& a)
{
    doParsimPacking(b,a.addr);
    doParsimPacking(b,a.seqNum);
}

void __doUnpacking(omnetpp::cCommBuffer *b, StandardUnreachableNode& a)
{
    doParsimUnpacking(b,a.addr);
    doParsimUnpacking(b,a.seqNum);
}

class StandardUnreachableNodeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    StandardUnreachableNodeDescriptor();
    virtual ~StandardUnreachableNodeDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(StandardUnreachableNodeDescriptor)

StandardUnreachableNodeDescriptor::StandardUnreachableNodeDescriptor() : omnetpp::cClassDescriptor("inet::StandardUnreachableNode", "")
{
    propertynames = nullptr;
}

StandardUnreachableNodeDescriptor::~StandardUnreachableNodeDescriptor()
{
    delete[] propertynames;
}

bool StandardUnreachableNodeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<StandardUnreachableNode *>(obj)!=nullptr;
}

const char **StandardUnreachableNodeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *StandardUnreachableNodeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int StandardUnreachableNodeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int StandardUnreachableNodeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *StandardUnreachableNodeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "addr",
        "seqNum",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int StandardUnreachableNodeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addr")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNum")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *StandardUnreachableNodeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "unsigned int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **StandardUnreachableNodeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *StandardUnreachableNodeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int StandardUnreachableNodeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    StandardUnreachableNode *pp = (StandardUnreachableNode *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *StandardUnreachableNodeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    StandardUnreachableNode *pp = (StandardUnreachableNode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string StandardUnreachableNodeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    StandardUnreachableNode *pp = (StandardUnreachableNode *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->addr; return out.str();}
        case 1: return ulong2string(pp->seqNum);
        default: return "";
    }
}

bool StandardUnreachableNodeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    StandardUnreachableNode *pp = (StandardUnreachableNode *)object; (void)pp;
    switch (field) {
        case 1: pp->seqNum = string2ulong(value); return true;
        default: return false;
    }
}

const char *StandardUnreachableNodeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *StandardUnreachableNodeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    StandardUnreachableNode *pp = (StandardUnreachableNode *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->addr); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::AODVStandardControlPacketType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::AODVStandardControlPacketType"));
    e->insert(RREQ, "RREQ");
    e->insert(RREP, "RREP");
    e->insert(RERR, "RERR");
    e->insert(RREPACK, "RREPACK");
)

Register_Class(AODVStandardControlPacket)

AODVStandardControlPacket::AODVStandardControlPacket(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->packetType = 0;
}

AODVStandardControlPacket::AODVStandardControlPacket(const AODVStandardControlPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

AODVStandardControlPacket::~AODVStandardControlPacket()
{
}

AODVStandardControlPacket& AODVStandardControlPacket::operator=(const AODVStandardControlPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVStandardControlPacket::copy(const AODVStandardControlPacket& other)
{
    this->packetType = other.packetType;
}

void AODVStandardControlPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
}

void AODVStandardControlPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
}

unsigned int AODVStandardControlPacket::getPacketType() const
{
    return this->packetType;
}

void AODVStandardControlPacket::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

class AODVStandardControlPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVStandardControlPacketDescriptor();
    virtual ~AODVStandardControlPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVStandardControlPacketDescriptor)

AODVStandardControlPacketDescriptor::AODVStandardControlPacketDescriptor() : omnetpp::cClassDescriptor("inet::AODVStandardControlPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

AODVStandardControlPacketDescriptor::~AODVStandardControlPacketDescriptor()
{
    delete[] propertynames;
}

bool AODVStandardControlPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVStandardControlPacket *>(obj)!=nullptr;
}

const char **AODVStandardControlPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVStandardControlPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVStandardControlPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int AODVStandardControlPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *AODVStandardControlPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int AODVStandardControlPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVStandardControlPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **AODVStandardControlPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AODVStandardControlPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AODVStandardControlPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVStandardControlPacket *pp = (AODVStandardControlPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AODVStandardControlPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardControlPacket *pp = (AODVStandardControlPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AODVStandardControlPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardControlPacket *pp = (AODVStandardControlPacket *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        default: return "";
    }
}

bool AODVStandardControlPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVStandardControlPacket *pp = (AODVStandardControlPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *AODVStandardControlPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *AODVStandardControlPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardControlPacket *pp = (AODVStandardControlPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(AODVStandardRREQ)

AODVStandardRREQ::AODVStandardRREQ(const char *name) : ::inet::AODVStandardControlPacket(name)
{
    this->setPacketType(RREQ);

    this->joinFlag = false;
    this->repairFlag = false;
    this->gratuitousRREPFlag = false;
    this->destOnlyFlag = false;
    this->unknownSeqNumFlag = false;
    this->hopCount = 0;
    this->rreqId = 0;
    this->destSeqNum = 0;
    this->originatorSeqNum = 0;
}

AODVStandardRREQ::AODVStandardRREQ(const AODVStandardRREQ& other) : ::inet::AODVStandardControlPacket(other)
{
    copy(other);
}

AODVStandardRREQ::~AODVStandardRREQ()
{
}

AODVStandardRREQ& AODVStandardRREQ::operator=(const AODVStandardRREQ& other)
{
    if (this==&other) return *this;
    ::inet::AODVStandardControlPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVStandardRREQ::copy(const AODVStandardRREQ& other)
{
    this->joinFlag = other.joinFlag;
    this->repairFlag = other.repairFlag;
    this->gratuitousRREPFlag = other.gratuitousRREPFlag;
    this->destOnlyFlag = other.destOnlyFlag;
    this->unknownSeqNumFlag = other.unknownSeqNumFlag;
    this->hopCount = other.hopCount;
    this->rreqId = other.rreqId;
    this->destAddr = other.destAddr;
    this->destSeqNum = other.destSeqNum;
    this->originatorAddr = other.originatorAddr;
    this->originatorSeqNum = other.originatorSeqNum;
}

void AODVStandardRREQ::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::AODVStandardControlPacket::parsimPack(b);
    doParsimPacking(b,this->joinFlag);
    doParsimPacking(b,this->repairFlag);
    doParsimPacking(b,this->gratuitousRREPFlag);
    doParsimPacking(b,this->destOnlyFlag);
    doParsimPacking(b,this->unknownSeqNumFlag);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->rreqId);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->destSeqNum);
    doParsimPacking(b,this->originatorAddr);
    doParsimPacking(b,this->originatorSeqNum);
}

void AODVStandardRREQ::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::AODVStandardControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->joinFlag);
    doParsimUnpacking(b,this->repairFlag);
    doParsimUnpacking(b,this->gratuitousRREPFlag);
    doParsimUnpacking(b,this->destOnlyFlag);
    doParsimUnpacking(b,this->unknownSeqNumFlag);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->rreqId);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->destSeqNum);
    doParsimUnpacking(b,this->originatorAddr);
    doParsimUnpacking(b,this->originatorSeqNum);
}

bool AODVStandardRREQ::getJoinFlag() const
{
    return this->joinFlag;
}

void AODVStandardRREQ::setJoinFlag(bool joinFlag)
{
    this->joinFlag = joinFlag;
}

bool AODVStandardRREQ::getRepairFlag() const
{
    return this->repairFlag;
}

void AODVStandardRREQ::setRepairFlag(bool repairFlag)
{
    this->repairFlag = repairFlag;
}

bool AODVStandardRREQ::getGratuitousRREPFlag() const
{
    return this->gratuitousRREPFlag;
}

void AODVStandardRREQ::setGratuitousRREPFlag(bool gratuitousRREPFlag)
{
    this->gratuitousRREPFlag = gratuitousRREPFlag;
}

bool AODVStandardRREQ::getDestOnlyFlag() const
{
    return this->destOnlyFlag;
}

void AODVStandardRREQ::setDestOnlyFlag(bool destOnlyFlag)
{
    this->destOnlyFlag = destOnlyFlag;
}

bool AODVStandardRREQ::getUnknownSeqNumFlag() const
{
    return this->unknownSeqNumFlag;
}

void AODVStandardRREQ::setUnknownSeqNumFlag(bool unknownSeqNumFlag)
{
    this->unknownSeqNumFlag = unknownSeqNumFlag;
}

unsigned int AODVStandardRREQ::getHopCount() const
{
    return this->hopCount;
}

void AODVStandardRREQ::setHopCount(unsigned int hopCount)
{
    this->hopCount = hopCount;
}

unsigned int AODVStandardRREQ::getRreqId() const
{
    return this->rreqId;
}

void AODVStandardRREQ::setRreqId(unsigned int rreqId)
{
    this->rreqId = rreqId;
}

L3Address& AODVStandardRREQ::getDestAddr()
{
    return this->destAddr;
}

void AODVStandardRREQ::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

unsigned int AODVStandardRREQ::getDestSeqNum() const
{
    return this->destSeqNum;
}

void AODVStandardRREQ::setDestSeqNum(unsigned int destSeqNum)
{
    this->destSeqNum = destSeqNum;
}

L3Address& AODVStandardRREQ::getOriginatorAddr()
{
    return this->originatorAddr;
}

void AODVStandardRREQ::setOriginatorAddr(const L3Address& originatorAddr)
{
    this->originatorAddr = originatorAddr;
}

unsigned int AODVStandardRREQ::getOriginatorSeqNum() const
{
    return this->originatorSeqNum;
}

void AODVStandardRREQ::setOriginatorSeqNum(unsigned int originatorSeqNum)
{
    this->originatorSeqNum = originatorSeqNum;
}

class AODVStandardRREQDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVStandardRREQDescriptor();
    virtual ~AODVStandardRREQDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVStandardRREQDescriptor)

AODVStandardRREQDescriptor::AODVStandardRREQDescriptor() : omnetpp::cClassDescriptor("inet::AODVStandardRREQ", "inet::AODVStandardControlPacket")
{
    propertynames = nullptr;
}

AODVStandardRREQDescriptor::~AODVStandardRREQDescriptor()
{
    delete[] propertynames;
}

bool AODVStandardRREQDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVStandardRREQ *>(obj)!=nullptr;
}

const char **AODVStandardRREQDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVStandardRREQDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVStandardRREQDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount() : 11;
}

unsigned int AODVStandardRREQDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *AODVStandardRREQDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "joinFlag",
        "repairFlag",
        "gratuitousRREPFlag",
        "destOnlyFlag",
        "unknownSeqNumFlag",
        "hopCount",
        "rreqId",
        "destAddr",
        "destSeqNum",
        "originatorAddr",
        "originatorSeqNum",
    };
    return (field>=0 && field<11) ? fieldNames[field] : nullptr;
}

int AODVStandardRREQDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='j' && strcmp(fieldName, "joinFlag")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "repairFlag")==0) return base+1;
    if (fieldName[0]=='g' && strcmp(fieldName, "gratuitousRREPFlag")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destOnlyFlag")==0) return base+3;
    if (fieldName[0]=='u' && strcmp(fieldName, "unknownSeqNumFlag")==0) return base+4;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "rreqId")==0) return base+6;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+7;
    if (fieldName[0]=='d' && strcmp(fieldName, "destSeqNum")==0) return base+8;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorAddr")==0) return base+9;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorSeqNum")==0) return base+10;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVStandardRREQDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "unsigned int",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "L3Address",
        "unsigned int",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : nullptr;
}

const char **AODVStandardRREQDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AODVStandardRREQDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AODVStandardRREQDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREQ *pp = (AODVStandardRREQ *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AODVStandardRREQDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREQ *pp = (AODVStandardRREQ *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AODVStandardRREQDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREQ *pp = (AODVStandardRREQ *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getJoinFlag());
        case 1: return bool2string(pp->getRepairFlag());
        case 2: return bool2string(pp->getGratuitousRREPFlag());
        case 3: return bool2string(pp->getDestOnlyFlag());
        case 4: return bool2string(pp->getUnknownSeqNumFlag());
        case 5: return ulong2string(pp->getHopCount());
        case 6: return ulong2string(pp->getRreqId());
        case 7: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 8: return ulong2string(pp->getDestSeqNum());
        case 9: {std::stringstream out; out << pp->getOriginatorAddr(); return out.str();}
        case 10: return ulong2string(pp->getOriginatorSeqNum());
        default: return "";
    }
}

bool AODVStandardRREQDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREQ *pp = (AODVStandardRREQ *)object; (void)pp;
    switch (field) {
        case 0: pp->setJoinFlag(string2bool(value)); return true;
        case 1: pp->setRepairFlag(string2bool(value)); return true;
        case 2: pp->setGratuitousRREPFlag(string2bool(value)); return true;
        case 3: pp->setDestOnlyFlag(string2bool(value)); return true;
        case 4: pp->setUnknownSeqNumFlag(string2bool(value)); return true;
        case 5: pp->setHopCount(string2ulong(value)); return true;
        case 6: pp->setRreqId(string2ulong(value)); return true;
        case 8: pp->setDestSeqNum(string2ulong(value)); return true;
        case 10: pp->setOriginatorSeqNum(string2ulong(value)); return true;
        default: return false;
    }
}

const char *AODVStandardRREQDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 7: return omnetpp::opp_typename(typeid(L3Address));
        case 9: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *AODVStandardRREQDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREQ *pp = (AODVStandardRREQ *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getDestAddr()); break;
        case 9: return (void *)(&pp->getOriginatorAddr()); break;
        default: return nullptr;
    }
}

Register_Class(AODVStandardRREP)

AODVStandardRREP::AODVStandardRREP(const char *name) : ::inet::AODVStandardControlPacket(name)
{
    this->setPacketType(RREP);

    this->repairFlag = false;
    this->ackRequiredFlag = false;
    this->prefixSize = 0;
    this->hopCount = 0;
    this->destSeqNum = 0;
    this->originatorSeqNum = 0;
    this->lifeTime = 0;
    this->totalHopsToDest = 0;
}

AODVStandardRREP::AODVStandardRREP(const AODVStandardRREP& other) : ::inet::AODVStandardControlPacket(other)
{
    copy(other);
}

AODVStandardRREP::~AODVStandardRREP()
{
}

AODVStandardRREP& AODVStandardRREP::operator=(const AODVStandardRREP& other)
{
    if (this==&other) return *this;
    ::inet::AODVStandardControlPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVStandardRREP::copy(const AODVStandardRREP& other)
{
    this->repairFlag = other.repairFlag;
    this->ackRequiredFlag = other.ackRequiredFlag;
    this->prefixSize = other.prefixSize;
    this->hopCount = other.hopCount;
    this->destAddr = other.destAddr;
    this->destSeqNum = other.destSeqNum;
    this->originatorAddr = other.originatorAddr;
    this->originatorSeqNum = other.originatorSeqNum;
    this->lifeTime = other.lifeTime;
    this->totalHopsToDest = other.totalHopsToDest;
}

void AODVStandardRREP::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::AODVStandardControlPacket::parsimPack(b);
    doParsimPacking(b,this->repairFlag);
    doParsimPacking(b,this->ackRequiredFlag);
    doParsimPacking(b,this->prefixSize);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->destSeqNum);
    doParsimPacking(b,this->originatorAddr);
    doParsimPacking(b,this->originatorSeqNum);
    doParsimPacking(b,this->lifeTime);
    doParsimPacking(b,this->totalHopsToDest);
}

void AODVStandardRREP::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::AODVStandardControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->repairFlag);
    doParsimUnpacking(b,this->ackRequiredFlag);
    doParsimUnpacking(b,this->prefixSize);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->destSeqNum);
    doParsimUnpacking(b,this->originatorAddr);
    doParsimUnpacking(b,this->originatorSeqNum);
    doParsimUnpacking(b,this->lifeTime);
    doParsimUnpacking(b,this->totalHopsToDest);
}

bool AODVStandardRREP::getRepairFlag() const
{
    return this->repairFlag;
}

void AODVStandardRREP::setRepairFlag(bool repairFlag)
{
    this->repairFlag = repairFlag;
}

bool AODVStandardRREP::getAckRequiredFlag() const
{
    return this->ackRequiredFlag;
}

void AODVStandardRREP::setAckRequiredFlag(bool ackRequiredFlag)
{
    this->ackRequiredFlag = ackRequiredFlag;
}

unsigned int AODVStandardRREP::getPrefixSize() const
{
    return this->prefixSize;
}

void AODVStandardRREP::setPrefixSize(unsigned int prefixSize)
{
    this->prefixSize = prefixSize;
}

unsigned int AODVStandardRREP::getHopCount() const
{
    return this->hopCount;
}

void AODVStandardRREP::setHopCount(unsigned int hopCount)
{
    this->hopCount = hopCount;
}

L3Address& AODVStandardRREP::getDestAddr()
{
    return this->destAddr;
}

void AODVStandardRREP::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

unsigned int AODVStandardRREP::getDestSeqNum() const
{
    return this->destSeqNum;
}

void AODVStandardRREP::setDestSeqNum(unsigned int destSeqNum)
{
    this->destSeqNum = destSeqNum;
}

L3Address& AODVStandardRREP::getOriginatorAddr()
{
    return this->originatorAddr;
}

void AODVStandardRREP::setOriginatorAddr(const L3Address& originatorAddr)
{
    this->originatorAddr = originatorAddr;
}

unsigned int AODVStandardRREP::getOriginatorSeqNum() const
{
    return this->originatorSeqNum;
}

void AODVStandardRREP::setOriginatorSeqNum(unsigned int originatorSeqNum)
{
    this->originatorSeqNum = originatorSeqNum;
}

::omnetpp::simtime_t AODVStandardRREP::getLifeTime() const
{
    return this->lifeTime;
}

void AODVStandardRREP::setLifeTime(::omnetpp::simtime_t lifeTime)
{
    this->lifeTime = lifeTime;
}

int AODVStandardRREP::getTotalHopsToDest() const
{
    return this->totalHopsToDest;
}

void AODVStandardRREP::setTotalHopsToDest(int totalHopsToDest)
{
    this->totalHopsToDest = totalHopsToDest;
}

class AODVStandardRREPDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVStandardRREPDescriptor();
    virtual ~AODVStandardRREPDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVStandardRREPDescriptor)

AODVStandardRREPDescriptor::AODVStandardRREPDescriptor() : omnetpp::cClassDescriptor("inet::AODVStandardRREP", "inet::AODVStandardControlPacket")
{
    propertynames = nullptr;
}

AODVStandardRREPDescriptor::~AODVStandardRREPDescriptor()
{
    delete[] propertynames;
}

bool AODVStandardRREPDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVStandardRREP *>(obj)!=nullptr;
}

const char **AODVStandardRREPDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVStandardRREPDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVStandardRREPDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int AODVStandardRREPDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *AODVStandardRREPDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "repairFlag",
        "ackRequiredFlag",
        "prefixSize",
        "hopCount",
        "destAddr",
        "destSeqNum",
        "originatorAddr",
        "originatorSeqNum",
        "lifeTime",
        "totalHopsToDest",
    };
    return (field>=0 && field<10) ? fieldNames[field] : nullptr;
}

int AODVStandardRREPDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "repairFlag")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackRequiredFlag")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixSize")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "destSeqNum")==0) return base+5;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorAddr")==0) return base+6;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorSeqNum")==0) return base+7;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifeTime")==0) return base+8;
    if (fieldName[0]=='t' && strcmp(fieldName, "totalHopsToDest")==0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVStandardRREPDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "unsigned int",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "L3Address",
        "unsigned int",
        "simtime_t",
        "int",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : nullptr;
}

const char **AODVStandardRREPDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AODVStandardRREPDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AODVStandardRREPDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREP *pp = (AODVStandardRREP *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AODVStandardRREPDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREP *pp = (AODVStandardRREP *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AODVStandardRREPDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREP *pp = (AODVStandardRREP *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getRepairFlag());
        case 1: return bool2string(pp->getAckRequiredFlag());
        case 2: return ulong2string(pp->getPrefixSize());
        case 3: return ulong2string(pp->getHopCount());
        case 4: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 5: return ulong2string(pp->getDestSeqNum());
        case 6: {std::stringstream out; out << pp->getOriginatorAddr(); return out.str();}
        case 7: return ulong2string(pp->getOriginatorSeqNum());
        case 8: return simtime2string(pp->getLifeTime());
        case 9: return long2string(pp->getTotalHopsToDest());
        default: return "";
    }
}

bool AODVStandardRREPDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREP *pp = (AODVStandardRREP *)object; (void)pp;
    switch (field) {
        case 0: pp->setRepairFlag(string2bool(value)); return true;
        case 1: pp->setAckRequiredFlag(string2bool(value)); return true;
        case 2: pp->setPrefixSize(string2ulong(value)); return true;
        case 3: pp->setHopCount(string2ulong(value)); return true;
        case 5: pp->setDestSeqNum(string2ulong(value)); return true;
        case 7: pp->setOriginatorSeqNum(string2ulong(value)); return true;
        case 8: pp->setLifeTime(string2simtime(value)); return true;
        case 9: pp->setTotalHopsToDest(string2long(value)); return true;
        default: return false;
    }
}

const char *AODVStandardRREPDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: return omnetpp::opp_typename(typeid(L3Address));
        case 6: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *AODVStandardRREPDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREP *pp = (AODVStandardRREP *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getDestAddr()); break;
        case 6: return (void *)(&pp->getOriginatorAddr()); break;
        default: return nullptr;
    }
}

Register_Class(AODVStandardRERR)

AODVStandardRERR::AODVStandardRERR(const char *name) : ::inet::AODVStandardControlPacket(name)
{
    this->setPacketType(RERR);

    unreachableNodes_arraysize = 0;
    this->unreachableNodes = 0;
    this->noDeleteFlag = false;
    this->destCount = 0;
}

AODVStandardRERR::AODVStandardRERR(const AODVStandardRERR& other) : ::inet::AODVStandardControlPacket(other)
{
    unreachableNodes_arraysize = 0;
    this->unreachableNodes = 0;
    copy(other);
}

AODVStandardRERR::~AODVStandardRERR()
{
    delete [] this->unreachableNodes;
}

AODVStandardRERR& AODVStandardRERR::operator=(const AODVStandardRERR& other)
{
    if (this==&other) return *this;
    ::inet::AODVStandardControlPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVStandardRERR::copy(const AODVStandardRERR& other)
{
    delete [] this->unreachableNodes;
    this->unreachableNodes = (other.unreachableNodes_arraysize==0) ? nullptr : new StandardUnreachableNode[other.unreachableNodes_arraysize];
    unreachableNodes_arraysize = other.unreachableNodes_arraysize;
    for (unsigned int i=0; i<unreachableNodes_arraysize; i++)
        this->unreachableNodes[i] = other.unreachableNodes[i];
    this->noDeleteFlag = other.noDeleteFlag;
    this->destCount = other.destCount;
}

void AODVStandardRERR::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::AODVStandardControlPacket::parsimPack(b);
    b->pack(unreachableNodes_arraysize);
    doParsimArrayPacking(b,this->unreachableNodes,unreachableNodes_arraysize);
    doParsimPacking(b,this->noDeleteFlag);
    doParsimPacking(b,this->destCount);
}

void AODVStandardRERR::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::AODVStandardControlPacket::parsimUnpack(b);
    delete [] this->unreachableNodes;
    b->unpack(unreachableNodes_arraysize);
    if (unreachableNodes_arraysize==0) {
        this->unreachableNodes = 0;
    } else {
        this->unreachableNodes = new StandardUnreachableNode[unreachableNodes_arraysize];
        doParsimArrayUnpacking(b,this->unreachableNodes,unreachableNodes_arraysize);
    }
    doParsimUnpacking(b,this->noDeleteFlag);
    doParsimUnpacking(b,this->destCount);
}

void AODVStandardRERR::setUnreachableNodesArraySize(unsigned int size)
{
    StandardUnreachableNode *unreachableNodes2 = (size==0) ? nullptr : new StandardUnreachableNode[size];
    unsigned int sz = unreachableNodes_arraysize < size ? unreachableNodes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unreachableNodes2[i] = this->unreachableNodes[i];
    unreachableNodes_arraysize = size;
    delete [] this->unreachableNodes;
    this->unreachableNodes = unreachableNodes2;
}

unsigned int AODVStandardRERR::getUnreachableNodesArraySize() const
{
    return unreachableNodes_arraysize;
}

StandardUnreachableNode& AODVStandardRERR::getUnreachableNodes(unsigned int k)
{
    if (k>=unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unreachableNodes_arraysize, k);
    return this->unreachableNodes[k];
}

void AODVStandardRERR::setUnreachableNodes(unsigned int k, const StandardUnreachableNode& unreachableNodes)
{
    if (k>=unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unreachableNodes_arraysize, k);
    this->unreachableNodes[k] = unreachableNodes;
}

bool AODVStandardRERR::getNoDeleteFlag() const
{
    return this->noDeleteFlag;
}

void AODVStandardRERR::setNoDeleteFlag(bool noDeleteFlag)
{
    this->noDeleteFlag = noDeleteFlag;
}

unsigned int AODVStandardRERR::getDestCount() const
{
    return this->destCount;
}

void AODVStandardRERR::setDestCount(unsigned int destCount)
{
    this->destCount = destCount;
}

class AODVStandardRERRDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVStandardRERRDescriptor();
    virtual ~AODVStandardRERRDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVStandardRERRDescriptor)

AODVStandardRERRDescriptor::AODVStandardRERRDescriptor() : omnetpp::cClassDescriptor("inet::AODVStandardRERR", "inet::AODVStandardControlPacket")
{
    propertynames = nullptr;
}

AODVStandardRERRDescriptor::~AODVStandardRERRDescriptor()
{
    delete[] propertynames;
}

bool AODVStandardRERRDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVStandardRERR *>(obj)!=nullptr;
}

const char **AODVStandardRERRDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVStandardRERRDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVStandardRERRDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int AODVStandardRERRDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *AODVStandardRERRDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "unreachableNodes",
        "noDeleteFlag",
        "destCount",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int AODVStandardRERRDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='u' && strcmp(fieldName, "unreachableNodes")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "noDeleteFlag")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destCount")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVStandardRERRDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "StandardUnreachableNode",
        "bool",
        "unsigned int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **AODVStandardRERRDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AODVStandardRERRDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AODVStandardRERRDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRERR *pp = (AODVStandardRERR *)object; (void)pp;
    switch (field) {
        case 0: return pp->getUnreachableNodesArraySize();
        default: return 0;
    }
}

const char *AODVStandardRERRDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRERR *pp = (AODVStandardRERR *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AODVStandardRERRDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRERR *pp = (AODVStandardRERR *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getUnreachableNodes(i); return out.str();}
        case 1: return bool2string(pp->getNoDeleteFlag());
        case 2: return ulong2string(pp->getDestCount());
        default: return "";
    }
}

bool AODVStandardRERRDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRERR *pp = (AODVStandardRERR *)object; (void)pp;
    switch (field) {
        case 1: pp->setNoDeleteFlag(string2bool(value)); return true;
        case 2: pp->setDestCount(string2ulong(value)); return true;
        default: return false;
    }
}

const char *AODVStandardRERRDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(StandardUnreachableNode));
        default: return nullptr;
    };
}

void *AODVStandardRERRDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRERR *pp = (AODVStandardRERR *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getUnreachableNodes(i)); break;
        default: return nullptr;
    }
}

Register_Class(AODVStandardRREPACK)

AODVStandardRREPACK::AODVStandardRREPACK(const char *name) : ::inet::AODVStandardControlPacket(name)
{
    this->setPacketType(RREPACK);
}

AODVStandardRREPACK::AODVStandardRREPACK(const AODVStandardRREPACK& other) : ::inet::AODVStandardControlPacket(other)
{
    copy(other);
}

AODVStandardRREPACK::~AODVStandardRREPACK()
{
}

AODVStandardRREPACK& AODVStandardRREPACK::operator=(const AODVStandardRREPACK& other)
{
    if (this==&other) return *this;
    ::inet::AODVStandardControlPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVStandardRREPACK::copy(const AODVStandardRREPACK& other)
{
}

void AODVStandardRREPACK::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::AODVStandardControlPacket::parsimPack(b);
}

void AODVStandardRREPACK::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::AODVStandardControlPacket::parsimUnpack(b);
}

class AODVStandardRREPACKDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVStandardRREPACKDescriptor();
    virtual ~AODVStandardRREPACKDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVStandardRREPACKDescriptor)

AODVStandardRREPACKDescriptor::AODVStandardRREPACKDescriptor() : omnetpp::cClassDescriptor("inet::AODVStandardRREPACK", "inet::AODVStandardControlPacket")
{
    propertynames = nullptr;
}

AODVStandardRREPACKDescriptor::~AODVStandardRREPACKDescriptor()
{
    delete[] propertynames;
}

bool AODVStandardRREPACKDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVStandardRREPACK *>(obj)!=nullptr;
}

const char **AODVStandardRREPACKDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVStandardRREPACKDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVStandardRREPACKDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int AODVStandardRREPACKDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *AODVStandardRREPACKDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int AODVStandardRREPACKDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVStandardRREPACKDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **AODVStandardRREPACKDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AODVStandardRREPACKDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AODVStandardRREPACKDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREPACK *pp = (AODVStandardRREPACK *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AODVStandardRREPACKDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREPACK *pp = (AODVStandardRREPACK *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AODVStandardRREPACKDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREPACK *pp = (AODVStandardRREPACK *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool AODVStandardRREPACKDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREPACK *pp = (AODVStandardRREPACK *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *AODVStandardRREPACKDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *AODVStandardRREPACKDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVStandardRREPACK *pp = (AODVStandardRREPACK *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(WaitForRREP)

WaitForRREP::WaitForRREP(const char *name, short kind) : ::omnetpp::cMessage(name,kind)
{
    this->lastTTL = 0;
    this->fromInvalidEntry = false;
}

WaitForRREP::WaitForRREP(const WaitForRREP& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

WaitForRREP::~WaitForRREP()
{
}

WaitForRREP& WaitForRREP::operator=(const WaitForRREP& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void WaitForRREP::copy(const WaitForRREP& other)
{
    this->destAddr = other.destAddr;
    this->lastTTL = other.lastTTL;
    this->fromInvalidEntry = other.fromInvalidEntry;
}

void WaitForRREP::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->lastTTL);
    doParsimPacking(b,this->fromInvalidEntry);
}

void WaitForRREP::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->lastTTL);
    doParsimUnpacking(b,this->fromInvalidEntry);
}

L3Address& WaitForRREP::getDestAddr()
{
    return this->destAddr;
}

void WaitForRREP::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

unsigned int WaitForRREP::getLastTTL() const
{
    return this->lastTTL;
}

void WaitForRREP::setLastTTL(unsigned int lastTTL)
{
    this->lastTTL = lastTTL;
}

bool WaitForRREP::getFromInvalidEntry() const
{
    return this->fromInvalidEntry;
}

void WaitForRREP::setFromInvalidEntry(bool fromInvalidEntry)
{
    this->fromInvalidEntry = fromInvalidEntry;
}

class WaitForRREPDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    WaitForRREPDescriptor();
    virtual ~WaitForRREPDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(WaitForRREPDescriptor)

WaitForRREPDescriptor::WaitForRREPDescriptor() : omnetpp::cClassDescriptor("inet::WaitForRREP", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

WaitForRREPDescriptor::~WaitForRREPDescriptor()
{
    delete[] propertynames;
}

bool WaitForRREPDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<WaitForRREP *>(obj)!=nullptr;
}

const char **WaitForRREPDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *WaitForRREPDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int WaitForRREPDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int WaitForRREPDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *WaitForRREPDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "destAddr",
        "lastTTL",
        "fromInvalidEntry",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int WaitForRREPDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastTTL")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "fromInvalidEntry")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *WaitForRREPDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "unsigned int",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **WaitForRREPDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *WaitForRREPDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int WaitForRREPDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    WaitForRREP *pp = (WaitForRREP *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *WaitForRREPDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    WaitForRREP *pp = (WaitForRREP *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string WaitForRREPDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    WaitForRREP *pp = (WaitForRREP *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 1: return ulong2string(pp->getLastTTL());
        case 2: return bool2string(pp->getFromInvalidEntry());
        default: return "";
    }
}

bool WaitForRREPDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    WaitForRREP *pp = (WaitForRREP *)object; (void)pp;
    switch (field) {
        case 1: pp->setLastTTL(string2ulong(value)); return true;
        case 2: pp->setFromInvalidEntry(string2bool(value)); return true;
        default: return false;
    }
}

const char *WaitForRREPDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *WaitForRREPDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    WaitForRREP *pp = (WaitForRREP *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getDestAddr()); break;
        default: return nullptr;
    }
}

} // namespace inet

