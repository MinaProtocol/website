// Removes .html from a slug for backwards compatibility
let stripHTMLSuffix = s =>
  switch (String.split_on_char('.', s)) {
  | [] => ""
  | [slug, "html"] => slug
  | [slug, ..._] => slug
  };

module System = {
  type contentType = {id: string};
  type contentTypeSys = {sys: contentType};

  type sys = {
    id: string,
    contentType: contentTypeSys,
    createdAt: string,
    updatedAt: string,
  };

  type includes;

  type entry('a) = {
    sys,
    fields: 'a,
    includes,
  };
  type entries('a) = {
    items: array(entry('a)),
    includes,
  };
};

module Link = {
  type t = {
    linkType: string,
    id: string,
  };

  type entry = {sys: t};
};

module Image = {
  type file = {url: string};
  type t = {file};

  type entry = System.entry(t);
  type entries = System.entries(t);
};

module BlogPost = {
  let id = "test";
  let dateKeyName = "date";
  type t = {
    title: string,
    snippet: string,
    slug: string,
    subtitle: Js.Undefined.t(string),
    author: string,
    authorWebsite: Js.Undefined.t(string),
    date: string,
    text: string,
  };
  type entry = System.entry(t);
  type entries = System.entries(t);
};

module Announcement = {
  let id = "announcement";
  let dateKeyName = "date";
  type t = {
    title: string,
    snippet: string,
    slug: string,
    date: string,
    text: string,
    image: option(Image.entry),
  };
  type entry = System.entry(t);
  type entries = System.entries(t);
};

module JobPost = {
  let id = "jobPost";
  type t = {
    title: string,
    jobDescription: string,
    snippet: string,
    slug: string,
    openingType: string,
  };
  type entry = System.entry(t);
  type entries = System.entries(t);
};

module KnowledgeBaseResource = {
  let id = "knowledgeeBaseResource";
  type t = {
    title: string,
    url: string,
    image: Image.entry,
  };
  type entry = System.entry(t);
  type entries = System.entries(t);
  [@bs.get]
  external getImages: System.includes => array(Image.entry) = "Asset";
};

module KnowledgeBaseCategory = {
  let id = "knowledgeBaseCategory";
  type t = {
    title: string,
    resources: array(KnowledgeBaseResource.entry),
  };
  type entry = System.entry(t);
  type entries = System.entries(t);
};

module GenesisProfile = {
  let id = "genesisProfile";
  type t = {
    name: string,
    image: Image.entry,
    quote: option(string),
    memberLocation: string,
    twitter: option(string),
    github: option(string),
    publishDate: string,
    blogPost: BlogPost.entry,
  };

  type entry = System.entry(t);
  type entries = System.entries(t);
};

module TeamProfile = {
  let id = "teamMembers";
  type t = {
    name: string,
    image: Image.entry,
    title: string,
    bio: string,
    quote: option(string),
    twitter: option(string),
    github: option(string),
    linkedin: option(string),
  };
  type entry = System.entry(t);
  type entries = System.entries(t);
};

module Advisor = {
  let id = "advisors";
  type t = {
    name: string,
    image: Image.entry,
    title: string,
    bio: option(string),
  };
  type entry = System.entry(t);
  type entries = System.entries(t);
};

module Grant = {
  let id = "grants";
  type t = {
    title: string,
    grantType: option(string),
    contributer: string,
    description: string,
    repoSlug: option(string),
    projectSlug: option(string),
  };
  type entry = System.entry(t);
  type entries = System.entries(t);
};

module GenericMember = {
  type t = {
    name: string,
    image: Image.entry,
    title: string,
    quote: option(string),
    bio: option(string),
    twitter: option(string),
    github: option(string),
    linkedin: option(string),
    blogPost: BlogPost.entry,
    memberLocation: option(string),
    publishDate: option(string),
  };

  type entry = System.entry(t);
  type entries = System.entries(t);
};

module Press = {
  let id = "press";
  let dateKeyName = "datePublished";
  type t = {
    title: string,
    image: option(Image.entry),
    link: string,
    featured: bool,
    description: Js.Undefined.t(string),
    publisher: string,
    datePublished: string,
  };
  type entry = System.entry(t);
  type entries = System.entries(t);
};

module NormalizedPressBlog = {
  type t = {
    title: string,
    image: option(Image.entry),
    link: [ | `Slug(string) | `Remote(string)],
    featured: bool,
    description: option(string),
    snippet: option(string),
    publisher: option(string),
    date: string,
  };

  let ofBlog = (blog: BlogPost.t) => {
    {
      title: blog.title,
      image: None,
      link: `Slug(blog.slug),
      featured: true,
      description: Some(blog.snippet),
      snippet: None,
      publisher: Some(blog.author),
      date: blog.date,
    };
  };

  let ofAnnouncement = (announcement: Announcement.t) => {
    {
      title: announcement.title,
      image: None,
      link: `Slug(announcement.slug),
      featured: true,
      description: Some(announcement.snippet),
      snippet: None,
      publisher: None,
      date: announcement.date,
    };
  };

  let ofPress = (press: Press.t) => {
    {
      title: press.title,
      image: press.image,
      link: `Remote(press.link),
      featured: press.featured,
      description: Js.Undefined.toOption(press.description),
      snippet: None,
      publisher: Some(press.publisher),
      date: press.datePublished,
    };
  };

  let ofJobPost = (job: JobPost.t) => {
    {
      title: job.title,
      image: None,
      link: `Remote(job.slug),
      featured: true,
      description: Some(job.openingType),
      snippet: Some(job.snippet),
      publisher: Some("O(1) Labs"),
      date: "San Francisco" /* Hack: The date property is used as the middle text in the top label in Listmodule.re */
    };
  };

  type entry = System.entry(t);
  type entries = System.entries(t);
};
