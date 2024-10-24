#include "../../includes/controlador/PostsController.h"

void PostsController::getPosts() { postsServices.getPosts(); }

void PostsController::insertPost(const std::string &author,
                                 const std::string &content) {
  postsServices.insertPost(author, content);
}

void PostsController::getPostsByAuthor(const std::string &author) {
  postsServices.getPostsByAuthor(author);
}

void PostsController::getPostsOrderedByDate(const std::string &date) {
  postsServices.getPostsOrderedByDate(date);
}

void PostsController::addCommentToPost(const std::string &author,
                                       const std::string &date,
                                       const std::string &username,
                                       const std::string &content) {
  postsServices.addCommentToPost(author, date, username, content);
}

void PostsController::updatePostContent(const std::string &author,
                                        const std::string &date,
                                        const std::string &newContent) {
  postsServices.updatePostContent(author, date, newContent);
}

void PostsController::deletePostByAuthorAndDate(const std::string &author,
                                                const std::string &date) {
  postsServices.deletePostByAuthorAndDate(author, date);
}

void PostsController::markPostAsFeatured(const std::string &author,
                                         const std::string &date) {
  postsServices.markPostAsFeatured(author, date);
}
