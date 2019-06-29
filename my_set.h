//
// Created by ilya on 29.06.19.
//

#ifndef SET_TESTING_MY_SET_H

#ifndef SET_SET_H
#define SET_SET_H

#include <iterator>
#include <iostream>

template<typename T>
struct my_set {
private:
    struct base_node {
        base_node *left;
        base_node *right;
        base_node *parent;

        base_node() {
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        };

        virtual ~base_node() = default;

    };

    struct node : base_node {
        T value;

        explicit node(T const &x) : value(x) {};
    };

    size_t sz;
    base_node root;
// ==============================ITERATOR=======================================
    template<typename U>
    struct set_iterator;
public:
    using iterator = set_iterator<T const>;
    using reverse_iterator =std::reverse_iterator<set_iterator<T const>>;
    using const_iterator = iterator;
    using const_reverse_iterator = reverse_iterator;
private:
    template<typename U>
    struct set_iterator : public std::iterator<std::bidirectional_iterator_tag, U> {
    public:
        friend struct my_set;

        set_iterator() = default;

        set_iterator(set_iterator const &other) = default;

        set_iterator &operator++() {
            if (ptr->right != nullptr) {
                ptr = ptr->right;
                while (ptr->left != nullptr) {
                    ptr = ptr->left;
                }
            } else {
                while (ptr->parent->right == ptr) {
                    ptr = ptr->parent;
                }
                ptr = ptr->parent;
            }
            return *this;
        }

        set_iterator operator++(int) {
            set_iterator tmp = *this;
            ++*this;
            return tmp;
        }

        set_iterator &operator--() {
            if (ptr->left != nullptr) {
                ptr = ptr->left;
                while (ptr->right != nullptr) {
                    ptr = ptr->right;
                }
            } else {
                while (ptr->parent->left == ptr) {
                    ptr = ptr->parent;
                }
                ptr = ptr->parent;
            }
            return *this;
        }

        set_iterator operator--(int) {
            set_iterator tmp = *this;
            --*this;
            return tmp;
        }

        friend bool operator==(set_iterator const &a, set_iterator const &b) {
            return a.ptr == b.ptr;
        }

        friend bool operator!=(set_iterator const &a, set_iterator const &b) {
            return a.ptr != b.ptr;
        }

        U const &operator*() const {
            return static_cast<const node *>(ptr)->value;
        }

        U const *operator->() const {
            return &(static_cast<const node * > (ptr)->value);
        }

    private:
        set_iterator(const base_node *ptr) : ptr(ptr) {}

        const base_node *ptr;
    };

    std::pair<iterator, bool> do_insert(T const &x, base_node *cur) {
        while (true) {
            T &value = static_cast<node *> (cur)->value;
            if (x > value) {
                if (cur->right == nullptr) {
                    cur->right = new node(x);
                    cur->right->parent = cur;
                    return {cur->right, true};
                }
                cur = cur->right;
            } else if (x < value) {
                if (cur->left == nullptr) {
                    cur->left = new node(x);
                    cur->left->parent = cur;
                    return {cur->right, true};
                }
                cur = cur->left;
            } else {
                return {cur, false};
            }
        }
    }

    const_iterator do_lower_bound(T const &x, base_node *cur) const {
        while (true) {
            T const &value = static_cast<node *>(cur)->value;
            if (value < x) {
                if (cur->right == nullptr) {
                    auto tmp = const_iterator(cur);
                    return ++tmp;
                }
                cur = cur->right;
            } else {
                if (cur->left == nullptr) {
                    return cur;
                }
                cur = cur->left;
            }
        }
    };

    const_iterator do_upper_bound(T const &x, base_node *cur) const {
        iterator res = lower_bound(x);
        node *t = (node *) const_cast<base_node *>(res.ptr);
        if (res != end() && t->value == x) {
            return ++res;
        }
        return res;
    };

    const_iterator do_find(T const &x, base_node *cur) const {
        if (empty()) {
            return end();
        }
        iterator ans = lower_bound(x);
        node *t = (node *) const_cast<base_node *>(ans.ptr);
        if (ans != end() && t->value == x) {
            return ans;
        }
        return end();
    };

public:
    my_set() : sz(0), root() {}

    my_set(my_set const &other) : sz(0) {
        try {
            for (auto x = other.begin(); x != other.end(); x++) {
                insert(*x);
            }
        } catch (...) {
            clear();
            throw;
        }
    };

    ~my_set() {
        clear();
    }

    my_set &operator=(my_set const &other) {
        my_set tmp(other);
        swap(tmp, *this);
        return *this;
    }

    iterator begin() {
        base_node *cur = &root;
        while (cur->left != nullptr) {
            cur = cur->left;
        }
        return cur;
    }

    const_iterator cbegin() const {
        const base_node *cur = &root;
        while (cur->left != nullptr) {
            cur = cur->left;
        }
        return const_cast<base_node *const>(cur);
    }

    const_iterator begin() const {
        return cbegin();
    }

    iterator end() {
        return iterator(&root);
    }

    const_iterator end() const {
        return const_iterator(&root);
    }

    const_iterator cend() const {
        return const_iterator(&root);
    }

    reverse_iterator rbegin() {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(end());
    }

    const_reverse_iterator crbegin() const {
        return const_reverse_iterator(end());
    }

    reverse_iterator rend() {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(begin());
    }

    const_reverse_iterator crend() const {
        return const_reverse_iterator(begin());
    }

    std::pair<iterator, bool> insert(T const &x) {
        if (empty()) {
            root.left = new node(x);
            root.left->parent = &root;
            sz++;
            return {root.left, true};
        }
        auto new_v = do_insert(x, root.left);
        if (new_v.second) {
            sz++;
        }
        return new_v;
    }

    const_iterator find(T const &x) const {
        return do_find(x, root.left);
    }

    iterator do_erase(base_node *cur) {
        iterator tmp_it = cur;
        tmp_it++;
        if (cur->right != nullptr && cur->left != nullptr) {
            base_node *tmp = cur->left;
            while (tmp->right != nullptr) {
                tmp = tmp->right;
            }
            node x(*static_cast<node *> (tmp));
            node y(*static_cast<node *> (cur));
            if (x.parent != nullptr) {
                if (x.parent->left == tmp) {
                    x.parent->left = cur;
                } else x.parent->right = cur;
            }
            if (y.parent != nullptr) {
                if (y.parent->left == cur) {
                    y.parent->left = tmp;
                } else y.parent->right = tmp;
            }
            if (x.right != nullptr) {
                x.right->parent = cur;
            }
            if (x.left != nullptr) {
                x.left->parent = cur;
            }
            if (y.right != nullptr) {
                y.right->parent = tmp;
            }
            if (y.left != nullptr) {
                y.left->parent = tmp;
            }
            std::swap(cur->parent, tmp->parent);
            std::swap(cur->right, tmp->right);
            std::swap(cur->left, tmp->left);

            do_erase(cur);
        } else if (cur->right == nullptr || cur->left == nullptr) {
            if (cur->right == nullptr) {
                if (cur->parent != nullptr) {
                    if (cur->parent->right == cur) {
                        cur->parent->right = cur->left;
                    } else {
                        cur->parent->left = cur->left;
                    }
                }
                if (cur->left != nullptr) {
                    cur->left->parent = cur->parent;
                }
            } else {
                if (cur->parent != nullptr) {
                    if (cur->parent->right == cur) {
                        cur->parent->right = cur->right;
                    } else {
                        cur->parent->left = cur->right;
                    }
                }
                cur->right->parent = cur->parent;
            }
            delete cur;
        }
        return tmp_it;
    }

    iterator erase(const_iterator it) {
        sz--;
        return do_erase(const_cast<base_node *>(it.ptr));
    }

    const_iterator lower_bound(T const &x) const {
        if (empty()) {
            return end();
        }
        return do_lower_bound(x, root.left);
    }

    const_iterator upper_bound(T const &x) const {
        if (empty()) {
            return end();
        }
        return do_upper_bound(x, root.left);
    }

    bool empty() const {
        return root.left == nullptr;
    }

    size_t size() const {
        return sz;
    }

    void clear() {
        iterator it = begin();
        while (it != end()) {
            it = erase(it);
        }
    }

    friend void swap(my_set<T> &a, my_set<T> &b) {
        std::swap(a.root, b.root);
        std::swap(a.sz, b.sz);
        if (b.root.left != nullptr) {
            b.root.left->parent = &b.root;
        }
        if (a.root.left != nullptr) {
            a.root.left->parent = &a.root;
        }
    }
};


#endif //SET_SET_H

#define SET_TESTING_MY_SET_H

#endif //SET_TESTING_MY_SET_H