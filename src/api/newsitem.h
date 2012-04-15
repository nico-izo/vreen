#ifndef VK_NEWSITEM_H
#define VK_NEWSITEM_H

#include <QSharedDataPointer>
#include <QVariant>
#include "attachment.h"

namespace vk {

class NewsItemData;

class VK_SHARED_EXPORT NewsItem
{
public:

    enum Type {
        Post,
        Photo,
        PhotoTag,
        Note
    };

    NewsItem();
    NewsItem(const NewsItem &);
    NewsItem &operator=(const NewsItem &);
    ~NewsItem();

    static NewsItem fromData(const QVariant &data);

    void setData(const QVariantMap &data);
    QVariantMap data() const;
    AttachmentList attachments() const;
    void setAttachments(const AttachmentList &attachments);
    Type type() const;
    void setType(Type type);
    int postId() const;
    void setPostId(int postId);
    int sourceId() const;
    void setSourceId(int sourceId);
    QString body() const;
    void setBody(const QString &body);
    QDateTime date() const;
    void setDate(const QDateTime &date);

    QVariant property(const QString &name, const QVariant &def = QVariant()) const;
    template<typename T>
    T property(const char *name, const T &def) const
    { return qVariantValue<T>(property(name, qVariantFromValue<T>(def))); }
    void setProperty(const QString &name, const QVariant &value);
    QStringList dynamicPropertyNames() const;
protected:
    NewsItem(const QVariantMap &data);
private:
    QSharedDataPointer<NewsItemData> d;
};
typedef QList<NewsItem> NewsItemList;

} // namespace vk

Q_DECLARE_METATYPE(vk::NewsItem)
Q_DECLARE_METATYPE(vk::NewsItemList)

#endif // VK_NEWSITEM_H