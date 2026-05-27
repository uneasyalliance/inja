#ifndef INCLUDE_INJA_TOKEN_HPP_
#define INCLUDE_INJA_TOKEN_HPP_

#include <string>
#include <string_view>

namespace inja {

/*!
 * \brief Helper-class for the inja Lexer.
 */
struct Token {
  enum class Kind {
    Text,
    ExpressionOpen,     // {{
    ExpressionClose,    // }}
    LineStatementOpen,  // user defined
    LineClose,          // \n
    StatementOpen,      // {%
    StatementClose,     // %}
    LineCommentOpen,    // user defined
    CommentOpen,        // {#
    CommentClose,       // #}
    Id,                 // this, this.foo
    Number,             // 1, 2, -1, 5.2, -5.3
    String,             // "this"
    Plus,               // +
    Minus,              // -
    Times,              // *
    Slash,              // /
    Percent,            // %
    Power,              // ^
    Comma,              // ,
    Dot,                // .
    Colon,              // :
    LeftParen,          // (
    RightParen,         // )
    LeftBracket,        // [
    RightBracket,       // ]
    LeftBrace,          // {
    RightBrace,         // }
    Equal,              // ==
    NotEqual,           // !=
    GreaterThan,        // >
    GreaterEqual,       // >=
    LessThan,           // <
    LessEqual,          // <=
    Pipe,               // |
    Unknown,
    Eof,
  };

  Kind kind {Kind::Unknown};
  std::string_view text;

  explicit constexpr Token() = default;
  explicit constexpr Token(Kind kind, std::string_view text): kind(kind), text(text) {}

  std::string describe() const {
    switch (kind) {
    case Kind::Text:
      return "<text>";
    case Kind::LineClose:
      return "<eol>";
    case Kind::Eof:
      return "<eof>";
    default:
      return static_cast<std::string>(text);
    }
  }
};

} // namespace inja

#endif // INCLUDE_INJA_TOKEN_HPP_
